class Solution:
    def numDecodings(self, s: str) -> int:
        ans = 0
        dp = [0,1]

        MOD = 10**9+7
        ASTERISK = -1 

        for i in range(len(s)):
            ans = 0
            x = int(s[i]) if s[i] != '*' else ASTERISK

            # check validity
            if x == 0 and (i == 0 or s[i-1] == '0'):
                break

            # single digit decode
            if x == ASTERISK:
                ans = (ans + 9*dp[1]) % MOD
            elif x != 0:
                ans = (ans + dp[1]) % MOD

            # double digit decode
            if i > 0:
                prev = int(s[i-1]) if s[i-1] != '*' else ASTERISK
                
                if x == ASTERISK:
                    if prev == 1:           ans = (ans + 9*dp[0]) % MOD
                    elif prev == 2:         ans = (ans + 6*dp[0]) % MOD
                    elif prev == ASTERISK:  ans = (ans + 15*dp[0]) % MOD
                else:
                    if prev == 1:           ans = (ans + dp[0]) % MOD
                    elif prev == 2:
                        if 0 <= x <= 6:     ans = (ans + dp[0]) % MOD
                    elif prev == ASTERISK:
                        if 0 <= x <= 6:     ans = (ans + 2*dp[0]) % MOD
                        else:               ans = (ans + dp[0]) % MOD
            
            # update memory
            dp[0], dp[1] = dp[1], ans
            


        return ans