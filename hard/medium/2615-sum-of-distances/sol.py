class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        stats, n = {}, len(nums)
        arr = [0] * n

        # left to right --------------------
        for i in range(n):
            num = nums[i]

            # update metrics and proceed
            if num not in stats:
                stats[num] = [1,i]
            
            # fill arr
            else:
                count = stats[num][0]
                curr_sum = stats[num][1]
                arr[i] += i*count - curr_sum
                # update
                stats[num] = [stats[num][0]+1, stats[num][1]+i]


        stats = {}

        # right to left --------------------
        for i in range(n-1,-1,-1):
            num = nums[i]

            # update metrics and proceed
            if num not in stats:
                stats[num] = [1,i]
            
            # fill arr
            else:
                count = stats[num][0]
                curr_sum = stats[num][1]
                arr[i] += curr_sum - i*count
                # update
                stats[num] = [stats[num][0]+1, stats[num][1]+i]


        return arr