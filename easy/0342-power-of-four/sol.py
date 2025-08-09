class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False

        flag = False

        while n > 0:
            if n % 2 == 1 and n > 1:
                return False
            n >>= 1
            # switch state to count stages in 2
            flag = not flag  
        
        return flag