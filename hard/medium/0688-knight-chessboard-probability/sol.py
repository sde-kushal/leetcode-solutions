class Solution:
    def __init__(self):
        self.dp = None

    
    def within_grid(self,i,j,n):
        if i >= 0 and j >= 0 and i < n and j < n:
            return 1
        return 0

    
    def next_valid_paths(self,i,j,n):
        coords = []

        if self.within_grid(i-2,j-1,n):
            coords.append([i-2,j-1]) 
        if self.within_grid(i-1,j-2,n):
            coords.append([i-1,j-2])
        if self.within_grid(i-2,j+1,n):
            coords.append([i-2,j+1])
        if self.within_grid(i-1,j+2,n):
            coords.append([i-1,j+2])
        if self.within_grid(i+2,j-1,n):
            coords.append([i+2,j-1])
        if self.within_grid(i+1,j-2,n):
            coords.append([i+1,j-2])
        if self.within_grid(i+2,j+1,n):
            coords.append([i+2,j+1])
        if self.within_grid(i+1,j+2,n):
            coords.append([i+1,j+2])

        return coords



    def fn(self,i,j,n,k):
        if k == 0:
            return 1
        
        prob = 0
        
        if self.dp[k-1][i*n+j] != -1:
            prob = self.dp[k-1][i*n+j]
        
        else:
            paths = self.next_valid_paths(i,j,n)
            for path in paths:
                p = 1/8 * self.fn(path[0],path[1],n,k-1)
                prob += p

            self.dp[k-1][i*n+j] = prob


        return prob



    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        self.dp = [[-1 for _ in range(n*n)] for _ in range(k)]
        return self.fn(row,column,n,k)
    
    