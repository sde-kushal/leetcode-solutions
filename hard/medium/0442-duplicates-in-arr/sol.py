class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        dups = []
        for x in nums:
            num = abs(x)
            if nums[num-1] < 0:
                dups.append(num)
            nums[num-1] *= -1            

        return dups