class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x==0:
            return 0
        if n==0 or x==1:
            return 1
        if x==-1:
            return 1 if n % 2 == 0 else -1

        ans = 1.0
        reciprocal = True if n < 0 else False
        n = n if n > 0 else -1*n

        for i in range(n):
            if ans >= 0 and ans <= 0.00001:
                return ans

            if reciprocal:
                ans *= 1/x
            else:
                ans *= x

        return ans