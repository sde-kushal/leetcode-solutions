#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> lookback;
        vector<int> pre(nums.size(),0);
        int total = 0;

        lookback[0] = 1;

        for(int i=0;i<nums.size();i+=1) {
            pre[i] = (i>0 ? pre[i-1] : 0) + nums[i];
            
            if(lookback.count(pre[i]-k)) 
                total += lookback[pre[i]-k];
            
            if(lookback.count(pre[i]))  lookback[pre[i]] += 1;
            else                        lookback[pre[i]] = 1;
        }

        return total;
    }
};