class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        n = len(arr)
        low, high = 0, n-1
        peak = -1

        while low <= high:
            mid = low + (high-low)//2
            mid = max(1, min(n-2, mid))

            # mid is peak
            if arr[mid-1] < arr[mid] and arr[mid] > arr[mid+1]:
                peak = mid 
                break
            
            # mid is at increasing slope
            if arr[mid-1] < arr[mid] < arr[mid+1]:
                low = mid+1

            # mid is at decreasing slope
            if arr[mid-1] > arr[mid] > arr[mid+1]:
                high = mid-1
        

        return peak