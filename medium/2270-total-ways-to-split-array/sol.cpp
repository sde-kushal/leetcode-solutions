#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<vector<long>> prefixSum(2, vector<long>(nums.size(),0));
        int ways = 0;

        for(int i=0;i<nums.size();i+=1){
            int backIndex = nums.size()-1-i;
            prefixSum[0][i] = (i>0?prefixSum[0][i-1]:0)+nums[i];
            prefixSum[1][backIndex] = (backIndex<nums.size()-1?prefixSum[1][backIndex+1]:0)+nums[backIndex];
        }

        for(int i=0;i<nums.size()-1;i+=1)
            if(prefixSum[0][i] >= prefixSum[1][i+1])
                ways += 1;
        
        return ways;
    }
};