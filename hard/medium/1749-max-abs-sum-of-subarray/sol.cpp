#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int globalMax = INT_MIN, globalMin = INT_MAX;
        int currMax = 0, currMin = 0;

        for(int i=0;i<nums.size();i+=1) {
            // kadanes algo for max sum
            currMax += nums[i];
            globalMax = max(globalMax,currMax);
            if(currMax < 0)
                currMax = 0;

            // kadanes algo for min sum
            currMin += nums[i];
            globalMin = min(globalMin, currMin);
            if(currMin > 0)
                currMin = 0;
        }

        return max(abs(globalMax), abs(globalMin));
    }
};