#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int local_min, limit;

        for(int i=nums.size()-2;i>=0;i-=1) {
            if(nums[i]==0) {
                dp[i] = INT_MAX;
                continue;
            }

            local_min = INT_MAX;
            limit = nums.size() < i+1+nums[i] ? nums.size() : i+1+nums[i];
            for(int j=i+1;j<limit;j+=1)
                local_min = min(local_min,dp[j]);
            
            dp[i] = local_min == INT_MAX ? INT_MAX : (1 + local_min);
        }

        return dp[0];
    }
};