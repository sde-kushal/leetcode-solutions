#include <vector>
using namespace std;

class Solution {
private:
    int xorSum(vector<int>& nums, int i, int currXOR) {
        if(i==nums.size()) return currXOR;
        return xorSum(nums,i+1,currXOR^nums[i]) + xorSum(nums,i+1,currXOR);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        return xorSum(nums,0,0);
    }
};