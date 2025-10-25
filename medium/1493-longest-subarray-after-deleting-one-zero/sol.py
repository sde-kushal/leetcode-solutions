class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        has_zero = False
        n = len(nums)
        l, r = -1, 0
        ans, prev_len = 0, 0

        while r <= n:
            if  r == n or nums[r] == 0:
                ans = max(ans, r-l+prev_len-2)  # 2 substrings both end with 0s
                prev_len = r-l
                l = r
                if r < n:
                    has_zero = True

            r += 1


        return ans if has_zero else n-1