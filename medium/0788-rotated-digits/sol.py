class Solution:
    def rotatedDigits(self, n: int) -> int:
        
        def isGood(num):
            flag = False
            while num > 0:
                dig = num % 10
                if dig in [3,4,7]: 
                    return False
                if dig in [2,5,6,9] and not flag:
                    flag = True
                
                num //= 10
            
            return flag
        
        
        dp = 0      # n=1 -> 0 good
        for num in range(2,n+1):
            dp += int(isGood(num))
        
        return dp