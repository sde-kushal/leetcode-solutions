class Solution:
    def maxArea(self, heights: List[int]) -> int:
        start, end = 0, len(heights)-1
        max_water = 0

        while start < end:
            water = (end - start) * min(heights[start], heights[end])
            max_water = max(max_water, water)

            if heights[start] > heights[end]:
                end -= 1
            elif heights[start] < heights[end]:
                start += 1
            else:
                start += 1
                end -= 1
                

        return max_water