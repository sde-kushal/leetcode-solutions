#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i+=2)
            if(i+1 < nums.size() && nums[i]!=nums[i+1])
                return nums[i];

        return nums[nums.size()-1];
    }
};