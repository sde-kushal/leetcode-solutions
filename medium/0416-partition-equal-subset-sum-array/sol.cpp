#include <vector>
#include <cmath>
using namespace std;

class Solution {
private:
    bool fn(int i, int diff, const int &sum, vector<int> &nums, vector<vector<int>> &dp) {
        int encoded = diff+sum;

        // return memoized
        if(dp[i][encoded] != -1)
            return dp[i][encoded];

        // base case    
        if(i==nums.size()-1) 
            return dp[i][encoded] = abs(diff) == nums[i];
        
        bool left = fn(i+1, nums[i]+diff, sum, nums, dp);     // LEFT SUBSET
        bool right = fn(i+1, diff-nums[i], sum, nums, dp);    // RIGHT SUBSET

        return dp[i][encoded] = left || right;
    }


public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        
        // if sum is odd then partition not possible
        if(sum%2!=0) return false;
        
        int k = 1+2*sum;
        vector<vector<int>> dp(n,vector<int>(k,-1));

        return fn(0,0,sum,nums,dp);
    }
};