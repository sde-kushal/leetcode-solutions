class Solution:
    def total_subslices(self, n):
        return int(((n-1)*(n-2))/2)


    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        curr_diff, curr_len = inf, 1
        slices = 0

        for i in range(1, len(nums)):
            num = nums[i]
            diff = num - nums[i-1]

            if diff == curr_diff:
                curr_len += 1
            else:
                if curr_len >= 3:
                    slices += self.total_subslices(curr_len)
                
                curr_diff = diff
                curr_len = 2


        # final check after loop ends
        if curr_len >= 3:
            slices += self.total_subslices(curr_len)

        return slices