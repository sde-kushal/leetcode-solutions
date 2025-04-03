#include <vector>
using namespace std;

class Solution {
private:
    int toInt(char ch) {
        return static_cast<int>(ch) - 48;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxLen = 0, cell  = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1,0));

        for(int i=0;i<rows;i+=1) {
            // run row-wise
            for(int j=i;j<cols;j+=1) {
                cell = toInt(matrix[i][j]);
                dp[i+1][j+1] = cell ? 1 + min(dp[i][j+1], min(dp[i][j], dp[i+1][j])) : 0;
                maxLen = max(maxLen, dp[i+1][j+1]);
            }

            // run col-wise
            if(i < cols)
                for(int j=i+1;j<rows;j+=1) {
                    cell = toInt(matrix[j][i]);
                    dp[j+1][i+1] = cell ? 1 + min(dp[j][i+1], min(dp[j][i], dp[j+1][i])) : 0;
                    maxLen = max(maxLen, dp[j+1][i+1]);
                }
        }

        return maxLen*maxLen;
    }
};