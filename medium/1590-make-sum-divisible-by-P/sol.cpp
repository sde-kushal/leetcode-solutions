#include <vector>
#include <limits.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int k = 0;
        for(int i=0;i<nums.size();i+=1)
            k = (k + nums[i]) % p;
        
        if(k==0)    return 0;

        int minLen = INT_MAX, prefixSum = 0;
        unordered_map<int,int> mod;
        mod[0] = -1;

        for(int i=0;i<nums.size();i+=1) {
            prefixSum = (prefixSum + nums[i]) % p;
            if(mod.find((prefixSum-k+p)%p)!=mod.end())
                minLen = min(minLen, i-mod[(prefixSum-k+p)%p]);
            mod[prefixSum] = i;
        }
        
        return minLen==INT_MAX || minLen==nums.size() ? -1 : minLen;
    }
};