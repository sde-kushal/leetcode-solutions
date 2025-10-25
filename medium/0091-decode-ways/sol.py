class Solution:
    def numDecodings(self, s: str) -> int:
        ans = 0
        dp = [0,1]

        for i in range(len(s)):
            ans = 0
            digit = int(s[i])

            # check validity
            if digit == 0 and (i == 0 or s[i-1] == '0'):
                break
            
            # consider digit as single decode
            if digit != 0:
                ans += dp[1]
            
            # consider digit as double decode
            if i > 0:
                if s[i-1] == '1' or (s[i-1] == '2' and 0 <= digit <= 6):
                    ans += dp[0]
            
            # update memory / dp
            dp[0], dp[1] = dp[1], ans



        return ans