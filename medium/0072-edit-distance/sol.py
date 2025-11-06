class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        
        def fn(i,wi):
            # base cases ###################
            if wi == n2: return max(0, n1-i)
            if i == n1:  return max(0, n2-wi)

            op = 10**3

            # if chars match ###################
            if word1[i] == word2[wi]:
                # skip
                if not dp[i+1][wi+1]: dp[i+1][wi+1] = fn(i+1,wi+1)
                op = dp[i+1][wi+1]

            # if chars dont match ###################
            else:
                # delete -------------------
                if not dp[i+1][wi]: dp[i+1][wi] = fn(i+1,wi)
                op = min(op, 1 + dp[i+1][wi])

                # replace -------------------
                if not dp[i+1][wi+1]: dp[i+1][wi+1] = fn(i+1,wi+1)
                op = min(op, 1 + dp[i+1][wi+1])

                # insert -------------------
                if not dp[i][wi+1]: dp[i][wi+1] = fn(i,wi+1)
                op = min(op, 1 + dp[i][wi+1])

            
            dp[i][wi] = op

            return op


        n1, n2 = len(word1),len(word2)
        dp = [[None for _ in range(n2+1)] for _ in range(n1+1)]
        
        return fn(0,0)