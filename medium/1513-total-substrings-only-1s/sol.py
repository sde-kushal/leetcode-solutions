class Solution:
    def numSub(self, s: str) -> int:
        
        MOD = 10**9+7
        curr = 0
        ans = 0

        for ch in s+"0":
            if ch == '1':
                curr = (curr + 1) % MOD
            elif curr > 0:
                if curr & 1: a,b = curr, (curr+1) // 2
                else:        a,b = curr+1, curr // 2
                ans = (ans + (a*b % MOD)) % MOD
                curr = 0
        

        return ans