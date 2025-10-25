class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cost = [0]*n
        min_cost, ans = inf, inf

        for i in range(m-2,-1,-1):
            for j in range(n):
                cell = grid[i][j]
                
                for k in range(n):
                    cost = moveCost[cell][k] + grid[i+1][k]
                    min_cost = min(min_cost, cost)
                
                grid[i][j] += min_cost
                min_cost = inf

                if i == 0:
                    ans = min(ans, grid[i][j])
        

        return ans