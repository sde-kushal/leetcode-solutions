class Solution:
    def divisorGame(self, n: int) -> bool:
        '''
        dp[2] = True
        dp[3] = !dp[2] = False
        dp[4] = !dp[3] or !dp[2] = True
        dp[5] = !dp[4] = False
        dp[6] = !dp[5] or !dp[4] or !dp[3] = True
        ...
        ...

        observation: dp[odd] = not dp[even] always = False
        as such, odd -> False always
                 even -> True always
        '''
        return n % 2 == 0