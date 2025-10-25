#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(amount+1, vector<unsigned int>(n+1,0));

        for(int i=0;i<=amount;i+=1) {
            for(int j=n-1;j>=0;j-=1) {
                unsigned int combinations = 0;
                for(int k=0;k<=i/coins[j];k+=1) {
                    int rem = i - k*coins[j];
                    if(rem == 0) combinations += 1;
                    else combinations += max((unsigned int)0, dp[rem][j+1]);
                }
                dp[i][j] = combinations;
            }
        }

        return dp[amount][0];
    }
};