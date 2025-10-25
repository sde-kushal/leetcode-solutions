#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        unordered_map<int,int> ref;
        vector<int> arr, prefix;
        int maxRamp = INT_MIN;

        for(int i=0;i<nums.size();i+=1)
            if(ref.find(nums[i])==ref.end()) {
                ref[nums[i]] = i;
                arr.push_back(nums[i]);
            }
        
        sort(arr.begin(),arr.end());

        for(int i=0;i<arr.size();i+=1)
            prefix.push_back(ref[arr[i]]);
        
        for(int i=1;i<arr.size();i+=1) {
            prefix[i] = min(prefix[i], prefix[i-1]);
            ref[arr[i]] = prefix[i];
        }

        for(int i=0;i<nums.size();i+=1)
            maxRamp = max(maxRamp, i - ref[nums[i]]);

        return maxRamp;
    }
};