class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        arr = [1] * n
        

        # left product prefix
        prod = 1
        for i in range(0,n-1):
            prod *= nums[i]
            arr[i+1] *= prod

        
        # right product suffix
        prod = 1
        for i in range(n-1,0,-1):
            prod *= nums[i]
            arr[i-1] *= prod


        return arr