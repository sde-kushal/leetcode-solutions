class Solution:
    def trap(self, heights: List[int]) -> int:
        n = len(heights)
        left, right = [0]*n, [0]*n
        total_water = 0
        
        # go LTR to store left max heights
        max_height_pos = -1

        for i, height in enumerate(heights):
            left[i] = max_height_pos
            if max_height_pos < 0 or height >= heights[max_height_pos]:
                max_height_pos = i

        
        # go RTL to store right max heights
        max_height_pos = -1

        for i in range(n-1, -1, -1):
            right[i] = max_height_pos
            if max_height_pos < 0 or heights[i] >= heights[max_height_pos]:
                max_height_pos = i
        

        # compute water for each cells
        for i, height in enumerate(heights):
            water = 0
            if left[i] != -1 and right[i] != -1:
                abs_water = min(heights[left[i]], heights[right[i]])
                water = max(0, abs_water - heights[i])
            
            
            total_water += water



        return total_water