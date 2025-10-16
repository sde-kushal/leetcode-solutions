import bisect 

class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        left_sum, right_sum = [0]*n, [0]*n
        ans = [0]*len(queries)

        nums = sorted(nums)

        for i, num in enumerate(nums):
            rev = n-1-i
            left_sum[i]     = (left_sum[i-1] if i>=0 else 0)        + nums[i]
            right_sum[rev]  = (right_sum[rev+1] if rev<n-1 else 0)  + nums[rev] 


        for i, query in enumerate(queries):
            # find index using BS   
            index = bisect.bisect_left(nums, query) - 1

            # rightSum - x + y - leftSum
            if index < 0:
                left_val    = 0
                right_val   = right_sum[index+1] - (n-(index+1))*query
            elif index >= n-1:
                left_val    = n*query - left_sum[n-1]
                right_val   = 0
            else:
                left_val    = (index+1)*query - left_sum[index]
                right_val   = right_sum[index+1] - (n-(index+1))*query

            # save to ans
            ans[i] = left_val + right_val


        return ans