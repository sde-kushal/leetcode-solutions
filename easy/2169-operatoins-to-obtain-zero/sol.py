class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        steps = 0
        while num1 > 0 and num2 > 0:
            if num1 >= num2:    
                t = max(1, (num1-num2) // num2)
                num1 -= t*num2
            else:               
                t = max(1, (num2-num1) // num1)
                num2 -= t*num1
            steps += t

        return steps