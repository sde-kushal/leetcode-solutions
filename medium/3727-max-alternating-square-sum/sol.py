class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        nums = sorted(nums, key=lambda x: abs(x), reverse=True)
        n = len(nums)
        mid = n//2 if n%2==0 else (n+1)//2
        result = 0
        
        for i in range(mid):
            result += nums[i]**2

        for i in range(mid,n):
            result -= nums[i]**2

        return result