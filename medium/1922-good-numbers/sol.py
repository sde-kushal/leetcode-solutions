class Solution:
    def countGoodNumbers(self, n: int) -> int:
        
        # BINARY EXPONENTIATION WITH MODULO
        # NOT NEEDED IN PYTHON BUT GOOD TO PRACTICE
        def binpow(a,n,mod):
            res = 1
            while n > 0:
                if n&1: res = (res*a) % mod
                a = (a*a) % mod 
                n >>= 1
            return res

        
        a,b = 0,0
        MOD = 10**9+7

        if n&1: a,b = (n+1)//2, (n-1)//2
        else:   a,b = n//2, n//2

        x = binpow(5,a,MOD)
        y = binpow(4,b,MOD)

        ans = 0
        if x&1: ans = ((2*((x-1)//2*y)%MOD)%MOD+y)%MOD
        else:   ans = 2*(((x//2)*y)%MOD)%MOD
        
        return ans