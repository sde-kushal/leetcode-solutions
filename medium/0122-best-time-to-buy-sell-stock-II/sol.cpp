#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;

        int localMin = INT_MAX, localMax = INT_MIN;
        int profit = 0;

        for(int i=0;i<prices.size();i+=1) {
            if(i==0 && prices[0] < prices[1])
                localMin = 0;
            else if(i==prices.size()-1 && prices[i] > prices[i-1])
                localMax = i;
            else if(i!=0 && i!=prices.size()-1)
                if(prices[i-1] <= prices[i] && prices[i+1] <= prices[i])
                    localMax = i;
                else if(prices[i-1] >= prices[i] && prices[i+1] >= prices[i])
                    localMin = i;
            
            if(localMin < localMax && prices[localMin] < prices[localMax]) {
                profit += prices[localMax] - prices[localMin];
                localMin = INT_MAX;
                localMax = INT_MIN;
            }
            
        }

        return profit;
    }
};