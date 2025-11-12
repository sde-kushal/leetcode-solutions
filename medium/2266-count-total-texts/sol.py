class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        n = len(pressedKeys)
        lastNum, lastIndex = -1, -1
        MOD = 10**9+7
        
        dp0,dp1,dp2,dp3 = 0,0,0,0
        ans, ways = 1, 1

        for i in range(n):
            dig = int(pressedKeys[i])
            
            if lastNum != dig:
                lastNum = dig
                lastIndex = i
                dp0,dp1,dp2,dp3 = 1,0,0,0
                ans = (ans * (ways % MOD)) % MOD
                ways = 0

            # consider 1 digit
            ways = dp0
            
            diff = i - lastIndex
            if diff > 0:
                # consider 2 digit
                ways = (ways + dp1) % MOD                       
                # consider 3 digit
                if diff >= 2: 
                    ways = (ways + dp2) % MOD
                # consider 4 digit         
                if (dig == 7 or dig == 9) and diff >= 3: 
                    ways = (ways + dp3) % MOD         
            
            dp3,dp2,dp1,dp0 = dp2,dp1,dp0,ways
        

        ans = (ans * (ways % MOD)) % MOD
        return ans