class Solution:
    def smallestNumber(self, n: int) -> int:
        low, high = 1, n
        ans = -1

        while low <= high:
            mid = low + (high-low)//2
            x = 2**mid - 1

            if x < n:
                low = mid+1
            else:
                ans = x
                high = mid-1

        
        return ans