class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        last_row = [1]   

        for row in range(2, rowIndex+2):
            curr_row = []
            
            for j in range(row):
                val = 1
                if j > 0 and j < row-1:
                    val = last_row[j-1] + last_row[j] 
            
                curr_row.append(val)
            
            last_row = curr_row


        return last_row