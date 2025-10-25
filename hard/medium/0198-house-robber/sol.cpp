#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)       return nums[0];
        else if(nums.size()==2)  return max(nums[0], nums[1]);

        vector<int> dp(nums.size(),0);

        for(int i=0;i<nums.size();i+=1) 
            dp[i] = nums[i] + max(i-2>=0 ? dp[i-2] : 0, i-3>=0 ? dp[i-3] : 0);

        return dp[nums.size()-1];
    }
};