#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avgs(nums.size(),-1);
        
        if(k*2 > nums.size()-1)
            return avgs;
        
        int left = 0, right = k*2;
        long sum = 0;

        for(int i=0;i<=right;i+=1)
            sum += nums[i];
        
        for(;right<nums.size();right+=1,left+=1) {
            avgs[left+k] = floor(sum/(k*2+1));
            sum -= nums[left];
            if(right+1<nums.size())
                sum += nums[right+1];
        }

        return avgs;
    }
};