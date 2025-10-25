class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        local_sum, global_sum = 0, nums[0]
        
        for num in nums:
            local_sum += num
            global_sum = max(global_sum,local_sum)
        
            if local_sum < 0:
                local_sum = 0

        
        
        return global_sum