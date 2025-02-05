#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currSum = nums[0], maxSum = 0;
        for(int i=1;i<nums.size();i+=1) {
            if(nums[i] > nums[i-1]) 
                currSum += nums[i];
            else {
                maxSum = max(maxSum, currSum);
                currSum = nums[i];
            }
        }
        
        maxSum = max(maxSum, currSum);
        return maxSum;
    }
};