#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;

        vector<int> dp(amount, -1);
        sort(coins.begin(), coins.end());

        for(int a=1;a<=amount;a+=1) 
            for(int i=0;i<coins.size();i+=1) {
                if(coins[i] > a)
                    continue;
                else if(coins[i] == a) 
                    dp[a-1] = 1;
                else if(dp[a-1-coins[i]] != -1)  
                    dp[a-1] = min(dp[a-1] == -1 ? INT_MAX : dp[a-1], 1 + dp[a-1-coins[i]]);
            }

        return dp[amount-1];
    }
};