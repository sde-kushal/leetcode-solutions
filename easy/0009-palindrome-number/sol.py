import math

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
            
        n = x
        rev = 0

        while n > 0:
            rev = rev*10 + n%10
            n = math.floor(n/10)
        
        return rev == x
