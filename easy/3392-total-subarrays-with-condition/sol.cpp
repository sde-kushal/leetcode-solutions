#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int left = 0, right = 2;
        int total = 0;

        for(;right<nums.size();right+=1,left+=1)
            if(2*(nums[left] + nums[right]) == nums[left+1])
                total += 1;

        return total;
    }
};