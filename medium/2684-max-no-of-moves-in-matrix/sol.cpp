#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int maxMove = 0;
        vector<vector<int>> dp(grid.size(),vector<int>(2,0));
        int k = 0;

        for(int j=grid[0].size()-2;j>=0;j-=1) {
            for(int i=0;i<grid.size();i+=1) {
                dp[i][k] = max((i > 0 && grid[i][j] < grid[i-1][j+1]) ? 1 + dp[i-1][k^1] : 0, max((grid[i][j] < grid[i][j+1]) ? 1 + dp[i][k^1] : 0, (i < grid.size()-1 && grid[i][j] < grid[i+1][j+1]) ? 1 + dp[i+1][k^1] : 0));

                if(j==0)
                    maxMove = max(maxMove, dp[i][k]);
            }

            k ^= 1;
        }

        return maxMove;
    }
};