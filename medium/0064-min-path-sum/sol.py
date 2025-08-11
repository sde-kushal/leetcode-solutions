class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[ 99_999 for _ in range(n+1)] for _ in range(m+1)]

        # not to hinder with last cell value
        dp[m][n-1], dp[m-1][n] = 0, 0

        # bottom up approach
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j])

        return dp[0][0]