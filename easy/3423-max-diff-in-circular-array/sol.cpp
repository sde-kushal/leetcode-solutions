#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxAdjDiff = 0;

        for(int index = 0; index < nums.size(); index += 1) {
            int adjIndex = (index + 1) % nums.size();
            maxAdjDiff = max(maxAdjDiff, abs(nums[index] - nums[adjIndex]));
        }

        return maxAdjDiff;
    }
};