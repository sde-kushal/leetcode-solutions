#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int low=0, high=0;
        int minLen = INT_MAX;
        vector<int> prefixSums(len);

        for(int i=0;i<len;i++) 
            if(i==0)    prefixSums[i] = nums[i];
            else        prefixSums[i] = nums[i] + prefixSums[i-1];

        if(prefixSums[prefixSums.size()-1] < target)
            return 0;
        
        while(high < len && prefixSums[high] < target)
            high += 1;

        if(high < len && prefixSums[high] < target)   
            return 0;

        while(high < len) {
            while(prefixSums[high] - prefixSums[low] >= target)
                low += 1;
            minLen = min(minLen, high - low + 1);
            high += 1;
        }

        return minLen;
    }
};