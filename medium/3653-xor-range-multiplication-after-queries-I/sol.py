class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        factors = [1]*len(nums)
        MOD = 1_000_000_007
        xor = 0
        
        for q in queries:
            for i in range(q[0],q[1]+1,q[2]):
                factors[i] = (factors[i]*q[3]) % MOD
        
        for i, num in enumerate(nums):
            xor ^= (factors[i]*num) % MOD
        
        return xor