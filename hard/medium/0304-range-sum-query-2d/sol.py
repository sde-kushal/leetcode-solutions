class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.m, self.n = len(matrix), len(matrix[0])
        self.leftSum   = [[0 for _ in range(self.n)] for _ in range(self.m)]
        self.rightSum  = [[0 for _ in range(self.n)] for _ in range(self.m)]

        for row in range(self.m):
            for i in range(self.n):
                j = self.n-1-i
                self.leftSum[row][i]  = matrix[row][i] + (self.leftSum[row][i-1] if i>0 else 0)
                self.rightSum[row][j] = matrix[row][j] + (self.rightSum[row][j+1] if j<self.n-1 else 0)

        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        total = 0

        for i in range(row1,row2+1):
            lsum = self.leftSum[i][col1-1] if col1>0 else 0
            rsum = self.rightSum[i][col2+1] if col2<self.n-1 else 0
            rowTotal = self.leftSum[i][self.n-1]
            total += rowTotal - lsum - rsum

        return total