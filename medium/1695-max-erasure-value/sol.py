class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        map = {}
        curr_sum, max_sum, n = 0, 0, len(nums)
        l, r = 0, 0


        while r < n:
            curr_sum += nums[r]
            
            if nums[r] in map:
                index = map[nums[r]] + 1
                while l < index:
                    curr_sum -= nums[l]
                    l += 1
            

            max_sum = max(max_sum, curr_sum)

            map[nums[r]] = r
            r += 1
        

        return max_sum