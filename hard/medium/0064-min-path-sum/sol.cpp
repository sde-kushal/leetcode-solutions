#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));

        for(int i=grid.size()-1;i>=0;i-=1)
            for(int j=grid[0].size()-1;j>=0;j-=1)
                if(i==grid.size()-1 && j==grid[0].size()-1)
                    dp[i][j] = grid[i][j];
                else 
                    dp[i][j] = grid[i][j] + min(i+1<grid.size() ? dp[i+1][j] : INT_MAX, j+1<grid[0].size() ? dp[i][j+1] : INT_MAX);
        
        return dp[0][0];
    }
};