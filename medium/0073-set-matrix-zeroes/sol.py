class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:

        rows, cols = len(matrix), len(matrix[0])
        MARK = '$'
        ROW_MARK, COL_MARK, SPL_MARK = '#', '@', '*'


        # grid traverse mark row wise left and col wise top as MARK
        for i in range(0,rows):
            for j in range(0,cols):
                
                cell = matrix[i][j]
                
                # mark if zero
                if cell == 0:
                    matrix[i][0] = MARK if i!=0 else (SPL_MARK if matrix[i][0]==COL_MARK or matrix[i][0]==SPL_MARK else ROW_MARK)
                    matrix[0][j] = MARK if j!=0 else (SPL_MARK if matrix[0][j]==ROW_MARK or matrix[0][j]==SPL_MARK else COL_MARK)
                


                
        # paint rows and cols with zeroes for marked positions
        for j in range(cols-1,0,-1):
            if matrix[0][j] == MARK:
                for i in range(0,rows):
                    matrix[i][j] = 0


        for i in range(rows-1,0,-1):
            if matrix[i][0] == MARK:
                for j in range(0,cols):
                    matrix[i][j] = 0




        # check for 0,0 pos
        if matrix[0][0] == SPL_MARK or matrix[0][0] == ROW_MARK:
            for j in range(1,cols):
                matrix[0][j] = 0
            if matrix[0][0] == ROW_MARK:
                matrix[0][0] = 0



        if matrix[0][0] == SPL_MARK or matrix[0][0] == COL_MARK:
            matrix[0][0] = 0
            for i in range(1,rows):
                matrix[i][0] = 0
