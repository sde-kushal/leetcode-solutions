class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        x1, x2, y1, y2 = inf, 0, inf, 0
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    x1 = min(x1,j)
                    x2 = max(x2,j)
                    y1 = min(y1,i)
                    y2 = max(y2,i)
        
        area = (x2-x1+1)*(y2-y1+1)
        return area