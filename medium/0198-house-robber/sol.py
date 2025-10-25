class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * (n+3)
        
        for i, num in enumerate(nums):
            dp[i+3] = nums[i] + max(dp[i+1], dp[i])
        
        return max(dp[n+2], dp[n+1])