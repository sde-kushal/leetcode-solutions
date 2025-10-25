class Solution:
    def __init__(self):
        self.dp = None
        self.ways, self.n = 0, 0
        self.total_sum, self.target = 0, 0
    

    
    def recursion(self, nums, i, curr_sum):
        if i == self.n:
            if curr_sum == self.target:
                self.ways += 1
                return True
            
            return False

        r1, r2 = False, False

        # check for + values
        val = curr_sum + nums[i]
        j = val + self.total_sum

        if self.dp[i][j] != False:
            r1 = self.recursion(nums, i+1, val)
            self.dp[i][j] = r1


        # check for - values
        val = curr_sum - nums[i]
        j = val + self.total_sum

        if self.dp[i][j] != False:
            r2 = self.recursion(nums, i+1, val)
            self.dp[i][j] = r2


        return r1 or r2




    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        self.n = len(nums)
        self.target = target
        self.total_sum = sum(nums)

        # i -> 0 to len(nums)-1 -> 20 rows
        # val -> 0 to 2*sum(nums) -> 2001 cols

        # x -> x + sum(nums)

        self.dp = [[None for _ in range(2*self.total_sum+1)] for _ in range(self.n)]
        self.recursion(nums, 0, 0)
        
        return self.ways