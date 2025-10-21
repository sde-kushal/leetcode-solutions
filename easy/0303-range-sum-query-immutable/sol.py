class NumArray:

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.leftSum  = [0]*self.n
        self.rightSum = [0]*self.n

        for i in range(self.n):
            j = self.n-1-i
            self.leftSum[i]  = nums[i] + (self.leftSum[i-1] if i>0 else 0)  
            self.rightSum[j] = nums[j] + (self.rightSum[j+1] if j<self.n-1 else 0) 



    def sumRange(self, left: int, right: int) -> int:
        lsum = self.leftSum[left-1] if left > 0 else 0
        rsum = self.rightSum[right+1] if right < self.n-1 else 0
        return self.leftSum[self.n-1] - (lsum + rsum)
