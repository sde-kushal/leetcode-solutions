#include <vector>
#include <limits.h>
#include <algortithm>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int copy, paste;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1;i>=1;i-=1)
            for(int c=n;c>=0;c-=1) {
                // copy option
                if(c==i) copy = INT_MAX;
                else     copy = 1 + dp[i][i];
                
                // paste option
                if(c==0 || i+c>n) paste = INT_MAX;
                else              paste = 1 + dp[i+c][c];

                dp[i][c] = min(min(copy,paste), INT_MAX-1);
            }

        return dp[1][0];
    }
};