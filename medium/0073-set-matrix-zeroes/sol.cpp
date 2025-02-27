#include <vector>
using namespace std;

#define FILL_ROW -2765
#define FILL_COL 8296
#define BOTH_WAY 9583

class Solution {
private:
    void fillRow(vector<vector<int>>& matrix, int r) {
        for(int i=0;i<matrix[0].size();i+=1)
            matrix[r][i] = 0;
    }
    
    void fillCol(vector<vector<int>>& matrix, int c) {
        for(int i=0;i<matrix.size();i+=1)
            matrix[i][c] = 0;
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        // set flags --------------------------------
        for(int i=0;i<matrix.size();i+=1)
            for(int j=0;j<matrix[0].size();j+=1) {
                if(i==0 && j==0 && matrix[i][j]==0)
                    matrix[i][j] = BOTH_WAY;
                else if(matrix[i][j]==0) {
                    matrix[i][0] = i==0 ? (matrix[0][0]==FILL_COL || matrix[0][0]==BOTH_WAY ? BOTH_WAY : FILL_ROW) : FILL_ROW;
                    matrix[0][j] = j==0 ? (matrix[0][0]==FILL_ROW || matrix[0][0]==BOTH_WAY ? BOTH_WAY : FILL_COL) : FILL_COL;
                }
            }
        
        // fill zeroes --------------------------------
        for(int i=1;i<matrix.size();i+=1)
            if(matrix[i][0]==FILL_ROW)
                fillRow(matrix,i);
            
        for(int i=1;i<matrix[0].size();i+=1)
            if(matrix[0][i]==FILL_COL)
                fillCol(matrix,i);
            
        if(matrix[0][0]==BOTH_WAY) {
            fillRow(matrix,0);
            fillCol(matrix,0);
        }
        else if(matrix[0][0]==FILL_ROW)
            fillRow(matrix,0);
        else if(matrix[0][0]==FILL_COL)
            fillCol(matrix,0);
    }
};