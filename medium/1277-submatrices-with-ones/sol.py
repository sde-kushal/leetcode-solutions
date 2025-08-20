class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        squares = 0
        
        for i in range(rows-1,-1,-1):
            for j in range(cols-1,-1,-1):
                if matrix[i][j] > 0:
                    right = matrix[i][j+1] if j < cols-1 else 0
                    bottom = matrix[i+1][j] if i < rows-1 else 0
                    bott_right = matrix[i+1][j+1] if i < rows-1 and j < cols-1 else 0

                    matrix[i][j] = 1 + min(right, bottom, bott_right)
                    squares += matrix[i][j]


        return squares