class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        prev = -1
        ans = True

        for i in range(len(nums)):
            num = nums[i]
            if num == 1:
                if prev >= 0 and i-prev-1 < k:
                    ans = False
                    break
                prev = i 

        return ans