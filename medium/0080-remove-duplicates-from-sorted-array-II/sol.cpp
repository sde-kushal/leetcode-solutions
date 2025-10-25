#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = -1, count = 0;
        for(int i=0;i<nums.size();i+=1) {
            if(i==0 || nums[i]!=nums[left]) {
                left += 1;
                nums[left] = nums[i];
                count = 1;
            }
            else {
                if(count == 2)  continue;
                left += 1;
                nums[left] = nums[i];
                count += 1;
            }
        }

        return left+1;
    }
};