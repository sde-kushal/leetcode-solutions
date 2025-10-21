class Solution:
    def reverse_list(self, nums, start, end):
        i, j = start, end
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1



    def nextPermutation(self, nums: List[int]) -> None:
        # find breakpoint
        bkpoint, n = -1, len(nums)

        for i in range(n-2,-1,-1):
            if nums[i] < nums[i+1]:
                bkpoint = i
                break
        

        # if breakpoint doesnt exist, reverse list and return
        if bkpoint == -1:
            self.reverse_list(nums, 0, n-1)
            return
        

        # find first num from back thats greater than breakpoint
        larger = -1

        for i in range(n-1,bkpoint,-1):
            if nums[i] > nums[bkpoint]:
                larger = i
                break
            
        
        # swap then reverse
        nums[bkpoint], nums[larger] = nums[larger], nums[bkpoint]
        self.reverse_list(nums, bkpoint+1, n-1)
