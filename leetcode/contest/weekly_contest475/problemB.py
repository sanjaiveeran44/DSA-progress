class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        indexMap = {}
        result = float('inf')

        for i,val in enumerate(nums):
            if val not in indexMap:
                indexMap[val] = []
            indexMap[val].append(i)

            if len(indexMap[val]) >= 3:
                a,b,c = indexMap[val][-3:]
                dist = abs(a-b)+abs(b-c)+abs(c-a)
                result = min(result,dist)
        return -1 if result == float('inf') else result