class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal_triangle = []

        for i in range(1,numRows+1):
            new_row = []
            size = i

            for j in range(size):
                val = 1
                if j > 0 and j < size-1:
                    val = pascal_triangle[i-2][j-1] + pascal_triangle[i-2][j]
                
                new_row.append(val)


            pascal_triangle.append(new_row)



        return pascal_triangle