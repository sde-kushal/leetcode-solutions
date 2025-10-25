#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int localMin, limit;

        for(int i=nums.size()-2;i>=0;i-=1) {
            if(nums[i]==0) {
                dp[i] = INT_MAX;
                continue;
            }

            localMin = INT_MAX;
            limit = nums.size() < i+1+nums[i] ? nums.size() : i+1+nums[i];
            
            for(int j=i+1;j<limit;j+=1)
                localMin = min(localMin,dp[j]);
        
            dp[i] = localMin==INT_MAX ? INT_MAX : 1+localMin;
        }

        return dp[0] != INT_MAX;
    }
};