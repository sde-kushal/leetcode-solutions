#include <vector>
#include <limits.h>
using namespace std;

class Solution {
private:
    int totalSetBits(int num) {
        int set_bits = 0;
        while(num > 0) {
            if(num%2!=0)  set_bits += 1;
            num >>= 1;
        }
        
        return set_bits;
    }

public:
    bool canSortArray(vector<int>& nums) {
        int prev_max = INT_MIN;
        int curr_min = nums[0], curr_max = nums[0];
        int curr_set_bits = totalSetBits(nums[0]);
        int new_bits;

        for (int i = 1; i <= nums.size(); i += 1) {
            if (i < nums.size())
                new_bits = totalSetBits(nums[i]);

            if (i == nums.size() || new_bits != curr_set_bits) {
                if (prev_max != INT_MIN && prev_max > curr_min)
                    return false;

                prev_max = curr_max;
                curr_min = i == nums.size() ? 0 : nums[i];
                curr_max = i == nums.size() ? 0 : nums[i];
                curr_set_bits = new_bits;
            } else {
                curr_min = min(curr_min, nums[i]);
                curr_max = max(curr_max, nums[i]);
            }
        }

        return true;
    }
};