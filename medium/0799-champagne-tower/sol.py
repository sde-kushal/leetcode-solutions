class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        dp = [[0 for _ in range(query_row+2)] for _ in range(query_row+2)]
        dp[0][0] = poured

        for i in range(query_row+1):
            for j in range(i+1):
                # check for overflow
                if dp[i][j] > 1:
                    rem = dp[i][j] - 1
                    dp[i][j] = 1

                    # pour to bottom level
                    dp[i+1][j] += rem/2
                    dp[i+1][j+1] += rem/2


        return dp[query_row][query_glass]