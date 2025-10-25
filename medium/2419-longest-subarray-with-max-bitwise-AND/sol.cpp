#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = nums[0];
        int local_count = 1,
            global_count = 1;

        for(int i=1; i<nums.size(); i+=1) {
            if(nums[i] > maxNum) {
                maxNum = nums[i];
                local_count = 1;
                global_count = 1;
                continue;
            }
            else if(nums[i] == maxNum) {
                if(nums[i-1] == maxNum) {
                    local_count += 1;
                    global_count = max(global_count, local_count);
                }
                else {
                    local_count = 1;
                }
            }
        }

        return global_count;
    }
};