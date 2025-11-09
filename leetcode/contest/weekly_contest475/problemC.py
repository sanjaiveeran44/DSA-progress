class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        n,m = len(grid), len(grid[0])

        dp = [[[-1]*(k+1) for _ in range(m)] for _ in range(n)]
        start_val = 2 if grid[0][0] == 2 else (1 if grid[0][0] == 1 else 0)
        start_count = 1 if grid[0][0] > 0 else 0
        dp[0][0][start_count] = start_val

        directions = [(1,0),(0,1)]

        for r in range(n):
            for c in range(m):
                for count in range(k+1):
                    if dp[r][c][count] == -1:
                        continue

                    for dr,dc in directions:
                        nr,nc = r+dr,c+dc
                        if nr >= n or nc >= m:
                            continue
                        cell_bonus = 1 if grid[nr][nc] > 0 else 0
                        next_used = count + cell_bonus
                        if next_used > k:
                            continue

                        score_gain = 2 if grid[nr][nc] == 2 else (1 if grid[nr][nc] == 1 else 0)
                        new_score = dp[r][c][count] + score_gain
                        dp[nr][nc][next_used] = max(dp[nr][nc][next_used],new_score)
        return max(dp[n-1][m-1])

