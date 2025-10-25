class Solution:
    def reverse_list(self, nums, start, end):
        i, j = start, end
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1


    def next_permutation(self, nums: List[int]) -> None:
        bkpoint, n = -1, len(nums)
        for i in range(n-2,-1,-1):
            if nums[i] < nums[i+1]:
                bkpoint = i
                break

        if bkpoint == -1:
            self.reverse_list(nums, 0, n-1)
            return
        
        larger = -1
        for i in range(n-1,bkpoint,-1):
            if nums[i] > nums[bkpoint]:
                larger = i
                break

        nums[bkpoint], nums[larger] = nums[larger], nums[bkpoint]
        self.reverse_list(nums, bkpoint+1, n-1)


    def factorial(self, n):
        fact = 1
        for i in range(1,n+1):
            fact *= i
        return fact


    def permute(self, nums: List[int]) -> List[List[int]]:
        steps = self.factorial(len(nums)) - 1  # first is OG array
        result = []
        result.append(nums)

        for _ in range(steps):
            arr = result[-1][:]
            self.next_permutation(arr)
            result.append(arr)

        return result