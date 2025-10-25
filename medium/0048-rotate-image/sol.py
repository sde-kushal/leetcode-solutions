class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        mid = math.floor(n/2)

        for i in range(mid):
            for j in range(i,n-i-1):
                # switch values of the 4 cells
                x, y = i, j
                temp = matrix[y][n-1-x]
                matrix[y][n-1-x] = matrix[x][y]

                for step in range(3):
                    x, y = y, n-1-x
                    matrix[y][n-1-x], temp = temp, matrix[y][n-1-x]
                    if step == 2:
                        temp = matrix[y][n-1-x]

                matrix[i][j] = temp