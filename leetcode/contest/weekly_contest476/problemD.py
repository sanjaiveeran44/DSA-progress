class Solution:
    def countStableSubarrays(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        right = [0] * n
        right[-1] = n - 1
        for i in range(n-2,-1,-1):
            if nums[i] <= nums[i+1]:
                right[i] = right[i+1]
            else:
                right[i] = i
        groups = [[] for _ in range(n)]
        for i in range(n):
            groups[right[i]].append(i)

        bit_cnt = [0]*(n+1)
        bit_sum = [0]*(n+1)
        def add(bit, i, val):
            while i <= n:
                bit[i] += val
                i += i & -i
        def pref(bit, i):
            s = 0
            while i > 0:
                s += bit[i]
                i -= i&-i
            return s
        def range_sum(bit, l, r):
            if r < l:
                return 0
            return pref(bit ,r) - pref(bit, l-1)
        q = len(queries)
        queries_at_r = [[] for _ in range(n)]
        for qi, (l,r) in enumerate(queries):
            queries_at_r[r].append((l,qi))
        result = [0] * q

        for r  in range(n):
            if r > 0:
                for i in groups[r-1]:
                    pos = i + 1
                    add(bit_cnt, pos, 1)
                    add(bit_sum, pos , right[i])
            for l, ql in queries_at_r[r]:
                    length = r - l + 1
                    total = length * (length + 1) // 2

                    count_bad = range_sum(bit_cnt, l + 1, r + 1)
                    sumR = range_sum(bit_sum, l+1,r+1)

                    bad = count_bad * r - sumR

                    result[ql] = total - bad
        return result
