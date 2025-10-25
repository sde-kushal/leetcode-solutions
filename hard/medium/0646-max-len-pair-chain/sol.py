class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        n = len(pairs)
        pairs = sorted(pairs)
        
        dp = [0]*(n+1)
        dp[n-1] = 1

        for i in range(n-1,-1,-1):
            index = n
            for j in range(i+1,n):
                if pairs[j][0] > pairs[i][1]:
                    index = j
                    break
            dp[i] = max(1+dp[index], dp[i+1])

        return dp[0]