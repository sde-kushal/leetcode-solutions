#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(k==0)    
            return;

        int offset = nums.size()-k;
        int index = 0;
        vector<int> rotated(nums.size(),0);

        for(int i=offset;i<offset+nums.size();i+=1) {
            rotated[index] = nums[i%nums.size()];
            index += 1;
        }

        nums = rotated;
    }
};