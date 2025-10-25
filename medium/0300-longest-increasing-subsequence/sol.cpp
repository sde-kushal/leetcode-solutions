#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for(int i=0;i<nums.size();i++) {
            if(lis.empty() || lis[lis.size()-1] < nums[i])
                lis.push_back(nums[i]);
            else {
                auto it = lower_bound(lis.begin(),lis.end(),nums[i]);
                if(it!=lis.end())
                    *it = nums[i];
            }
        }

        return lis.size();
    }
};