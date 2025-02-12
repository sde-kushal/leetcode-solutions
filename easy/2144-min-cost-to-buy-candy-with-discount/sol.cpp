#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int totalCost = 0;

        sort(cost.begin(),cost.end());

        for(int i=cost.size()-1; i>=0; i-=3) 
            totalCost += cost[i] + (i-1 >= 0 ? cost[i-1] : 0);

        return totalCost;
    }
};