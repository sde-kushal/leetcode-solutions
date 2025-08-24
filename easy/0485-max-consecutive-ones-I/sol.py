class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        l, r = -1, 0
        ans, n = 0, len(nums)

        while r <= n:
            if r == n or nums[r] == 0:
                ans = max(ans, r-l-1)
                l = r
            
            r += 1


        return ans