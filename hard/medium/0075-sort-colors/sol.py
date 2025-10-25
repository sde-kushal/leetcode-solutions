class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        LOWEST, MIDVAL, HIGHEST = 0, 1, 2
        low, mid, high = 0, 0, len(nums)-1

        # iterate till mid > high:
        while mid <= high:

            # if mid = 0 then swap with low and increment low
            if nums[mid] == LOWEST:
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            
            # if mid = 1 then increment
            elif nums[mid] == MIDVAL:
                mid += 1

            # if mid = 2 then swap with high and decrement high
            else:
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1