class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)

        # top right triangle
        for x in range(1,n):
            # accumulate values
            i, j = 0, x
            sorted_arr = []
            
            for y in range(n-x):
                sorted_arr.append(grid[i][j])
                i += 1
                j += 1
            
            # put sorted values in place
            sorted_arr = sorted(sorted_arr, reverse=False)
            i, j = 0, x

            for y in range(n-x):
                grid[i][j] = sorted_arr[y] 
                i += 1
                j += 1




        # bottom left triangle
        for x in range(0,n):
            # accumulate values
            i, j = x, 0
            sorted_arr = []
            
            for y in range(n-x):
                sorted_arr.append(grid[i][j])    
                i += 1
                j += 1
            
            # put sorted values in place
            sorted_arr = sorted(sorted_arr, reverse=True)
            i, j = x, 0

            for y in range(n-x):
                grid[i][j] = sorted_arr[y] 
                i += 1
                j += 1



        
        return grid