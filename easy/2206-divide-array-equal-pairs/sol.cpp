#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> seen;

        for(int i=0;i<nums.size();i+=1) {
            if(seen.count(nums[i]))     seen.erase(nums[i]);
            else                        seen.insert(nums[i]);
        }

        return seen.empty();
    }
};