#include <vector>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int maxBars = 0;

        for (int i = 0; i < costs.size();i+=1)
            if(costs[i] <= coins) {
                coins -= costs[i];
                maxBars += 1;
            }
            else
                break;

        return maxBars;
    }
};