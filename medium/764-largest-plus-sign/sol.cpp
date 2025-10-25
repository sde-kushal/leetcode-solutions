#include <vector>
#include <algorithm>
using namespace std;

#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3
#define MINE -1

class Solution {
private:
    int largestPlus;

    void topLeftToBottomRight(int &n, vector<vector<vector<int>>> &dp) {
        for(int i=0;i<n;i+=1)
            for(int j=0;j<n;j+=1) {
                if(dp[i][j] != MINE) {
                    dp[i][j] = 1 + (j==0 ? 0 : max(0, dp[i][j-1][LEFT]));
                }
            }
    }

    void botomRightToTopLeft(int &n, vector<vector<vector<int>>> &dp) {
        int plus;
        for(int i=n-1;i>=0;i-=1)
            for(int j=n-1;j>=0;j-=1) {
                if(dp[i][j][BOTTOM] == MINE) dp[i][j] = {0,0,0,0};
                else {
                    dp[i][j][BOTTOM] = 1 + (i==n-1 ? 0 : dp[i+1][j][BOTTOM]);
                    dp[i][j][RIGHT] = 1 + (j==n-1 ? 0 : dp[i][j+1][RIGHT]);

                    plus = min(dp[i][j][TOP], min(dp[i][j][BOTTOM], min(dp[i][j][LEFT], dp[i][j][RIGHT])));
                    largestPlus = max(largestPlus, plus);
                }
            }
    }

public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n,vector<int>(n,0));
        largestPlus = 0;

        // insert all mines
        for(int i=0;i<mines.size();i+=1)
            dp[mines[i][0]][mines[i][1]] = MINE;
        
        // solve for top and left
        topLeftToBottomRight(n, dp);

        // solve for bottom and right
        botomRightToTopLeft(n, dp);

        return largestPlus;
    }
};