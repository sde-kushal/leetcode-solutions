class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        xor1, xor2 = 0, 0

        for i in range(n+1):
            xor1 ^= i
        for i in range(n):
            xor2 ^= nums[i]
        
        return xor1 ^ xor2