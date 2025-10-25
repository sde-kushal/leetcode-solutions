#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> finds;
        int sum = 0;
        for(int i=0;i<nums.size();i+=1) {
            sum = (sum + nums[i]) % k;
            if((sum == 0 && i >= 1) || (finds.find(sum) != finds.end() && i-finds[sum] >= 2))
                return true;
            if(finds.find(sum) == finds.end())
                finds[sum] = i;
        }

        return false;
    }
};