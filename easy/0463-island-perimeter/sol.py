class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        
        def adjacentLands(i,j):
            t = 1 if i>0    and grid[i-1][j]==1 else 0
            b = 1 if i<m-1  and grid[i+1][j]==1 else 0
            l = 1 if j>0    and grid[i][j-1]==1 else 0
            r = 1 if j<n-1  and grid[i][j+1]==1 else 0
            return t+r+b+l

        def borderLandArea(i,j):
            if not(i==0 or j==0 or i==m-1 or j==n-1):
                return 0
            
            t = 1 if i==0   else 0
            b = 1 if i==m-1 else 0
            l = 1 if j==0   else 0
            r = 1 if j==n-1 else 0
            return t+r+b+l

        
        P = 0
        m, n = len(grid), len(grid[0])
        
        for i in range(m):
            for j in range(n):
                cell = grid[i][j]
                if cell == 0:   P += adjacentLands(i,j)
                else:           P += borderLandArea(i,j)
        
        return P