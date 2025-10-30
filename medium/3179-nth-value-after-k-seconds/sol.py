class Solution:
    def valueAfterKSeconds(self, n: int, k: int) -> int:
        a = [1]*n
        MOD = 10**9+7

        for _ in range(k):
            for i in range(1,n):
                a[i] = (a[i] + a[i-1]) % MOD
        
        return a[n-1]