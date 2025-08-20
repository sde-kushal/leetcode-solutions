class Solution:
    
    def containsCycle(self, grid: List[List[str]]) -> bool:
        def hashed(i,j,cols):
            return cols*i+j
        
        def decrypt(h,n):
            return [int((h-(h%n))/n), h%n]


        def dfs_has_cycle(start_row, start_col, m, n) -> bool:
            seen = set()
            stack = []

            stack.append(hashed(start_row,start_col,n))

            while stack:
                h = stack[-1]

                # cycle found and returned
                if h in seen:
                    return True 

                # process cell
                [i,j] = decrypt(h,cols)
                stack.pop()

                if i<m-1 and grid[i][j]==grid[i+1][j]:
                    stack.append(hashed(i+1,j,n))
                if j<n-1 and grid[i][j]==grid[i][j+1]:
                    stack.append(hashed(i,j+1,n))
                if i>0 and grid[i][j]==grid[i-1][j]:
                    stack.append(hashed(i-1,j,n))
                if j>0 and grid[i][j]==grid[i][j-1]:
                    stack.append(hashed(i,j-1,n))

                # mark seen
                grid[i][j] = '#'
                seen.add(h)
            

            return False


        # -------------------------------------------

        rows, cols = len(grid), len(grid[0])

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '#':
                    continue
                # simply reutrn if cycle exists
                if dfs_has_cycle(i,j,rows,cols):
                    return True
        


        return False
                