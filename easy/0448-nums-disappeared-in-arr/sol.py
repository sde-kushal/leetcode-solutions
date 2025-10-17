class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for num in nums:
            i = abs(num) - 1
            if nums[i] > 0:
                nums[i] *= -1
        
        disappeared = []
        for i, num in enumerate(nums):
            if num > 0:
                disappeared.append(i+1)
        
        return disappeared