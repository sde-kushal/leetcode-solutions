#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long maxPoints = 0;
        vector<long long> dp(n,0);

        // solve using dp from back to front
        for(int i=n-1;i>=0;i-=1) {
            int jumpedIndex = min(n,questions[i][1]+i+1); // find next jump index
            long long maxPossiblePointsAtJump = jumpedIndex == n ? 0 : dp[jumpedIndex]; // compute points max points earned
            dp[i] = max(maxPoints, (long long)(questions[i][0] + maxPossiblePointsAtJump)); // update to cost
            
            // update max count
            maxPoints = max(maxPoints, dp[i]);
        }

        return maxPoints;
    }
};