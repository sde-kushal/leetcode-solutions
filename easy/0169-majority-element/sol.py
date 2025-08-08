class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # ans and freq
        ans, freq = nums[0], 0

        for num in nums:
            # if freq = 0: ans = num and freq = 1
            if freq == 0:
                ans = num
                freq = 1
                
            else:
                # if num == ans: freq+1
                if num == ans:
                    freq += 1

                # else: freq-1
                else:
                    freq -= 1


        return ans