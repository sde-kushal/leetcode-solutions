class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        l, size = -1, len(nums)
        ans = 0
        flag = False
        
        for i in range(1+size):
            # count subarrays when non zero
            if i == size or nums[i] != 0:
                if flag: 
                    n = i-l
                    ans += int((n*(n+1))/2)
                    flag = False

            # increase size when zeroes
            else:
                if not flag:
                    l = i
                    flag = True

        return ans