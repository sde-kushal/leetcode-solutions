class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        SEEN = 2

        def bfsArea(r,c):
            area = 0
            stack = []

            stack.append((r,c))
            grid[r][c] = SEEN

            while stack:
                i, j = stack.pop()
                area += 1
                
                # TOP ===============================
                if i>0   and grid[i-1][j]==1: 
                    stack.append((i-1,j))
                    grid[i-1][j] = SEEN
                # BOTTOM ===============================
                if i<m-1 and grid[i+1][j]==1: 
                    stack.append((i+1,j))
                    grid[i+1][j] = SEEN
                # LEFT ===============================
                if j>0   and grid[i][j-1]==1: 
                    stack.append((i,j-1))
                    grid[i][j-1] = SEEN
                # RIGHT ===============================
                if j<n-1 and grid[i][j+1]==1: 
                    stack.append((i,j+1))
                    grid[i][j+1] = SEEN
            
            
            return area


        maxArea = 0
        m, n = len(grid), len(grid[0])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    maxArea = max(maxArea, bfsArea(i,j))

        return maxArea