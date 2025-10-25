#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        vector<int> temp;
        int currLen;

        for(int i=0;i<nums.size();i+=1) {
            currLen = ans.size();
            for(int j=0;j<currLen;j+=1) {
                temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};