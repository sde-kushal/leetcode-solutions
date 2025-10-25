class Solution:
    def countHousePlacements(self, n: int) -> int:
        f = [1,2]
        MOD = 1_000_000_007

        for i in range(2,n+1):
            t = (f[0] + f[1]) % MOD
            f[0] = f[1]
            f[1] = t
        
        return (f[1]**2) % MOD
        