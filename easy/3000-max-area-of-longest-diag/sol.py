class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        max_area, max_diag = 0, 0

        for dim in dimensions:
            diag = dim[0]**2 + dim[1]**2
            if max_diag <= diag:
                if max_diag == diag:
                    max_area = max(max_area, dim[0] * dim[1])
                else:
                    max_area = dim[0] * dim[1]

                max_diag = diag


        return max_area