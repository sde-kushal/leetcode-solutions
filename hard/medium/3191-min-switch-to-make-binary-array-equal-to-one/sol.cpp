#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int left = 0;
        int steps = 0;

        for(;left+2<nums.size()-1;left+=1) {
            if(!nums[left]) {
                nums[left] = !nums[left];
                nums[left+1] = !nums[left+1];
                nums[left+2] = !nums[left+2];
                steps += 1;
            }
        }

        if(nums[left]==nums[left+1] && nums[left+1]==nums[left+2]) {
            if(nums[left] == 0) 
                return steps + 1;
            return steps;
        }

        return -1;
    }
};