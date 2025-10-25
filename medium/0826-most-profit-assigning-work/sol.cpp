#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>> profits(difficulty.size(), vector<int>(2, 0));
        for(int i=0;i<difficulty.size();i+=1) {
            profits[i][0] = difficulty[i];
            profits[i][1] = profit[i];
        }

        sort(profits.begin(), profits.end());
        sort(worker.begin(), worker.end());

        int totalProfit = 0, maxProfit = 0;
        int j = -1;

        if(worker[worker.size()-1] < profits[0][0])
            return 0;

        for(int i=0;i<worker.size();i+=1) {
            while(j+1<difficulty.size() && profits[j+1][0] <= worker[i]) {
                j += 1;
                maxProfit = max(maxProfit, profits[j][1]);
            }
            
            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};