class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        evens, odds, alternates = 0, 0, 0
        last_even = False if nums[0] % 2 == 0 else True 

        for num in nums:
            if num % 2 == 0:
                evens += 1
                if not last_even:
                    alternates += 1
                    last_even = True
            else:
                odds += 1
                if last_even:
                    alternates += 1
                    last_even = False

        return max(evens, max(odds, alternates))