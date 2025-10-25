#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0, currSum = 0;
        int anamolies = 0, left = 0, right = k-1;
        unordered_map<int,int> counts;

        // calculate initial window sum and counts
        for(int i=left;i<=right;i+=1) {
            currSum += nums[i];
            if(counts.find(nums[i]) != counts.end()) {
                if(counts[nums[i]] == 1)
                    anamolies += 1;
                counts[nums[i]] += 1;
            }
            else
                counts[nums[i]] = 1;
        }
        
        // uodate is distinct entries
        if(anamolies == 0)
            maxSum = max(maxSum, currSum);

        for(right=right+1,left=left+1;right<nums.size();right+=1,left+=1) {
            currSum -= nums[left-1];
            currSum += nums[right];

            // handle left outgoing number
            if(counts[nums[left-1]] == 1)
                counts.erase(nums[left-1]);
            else {
                if(counts[nums[left-1]] == 2)
                    anamolies -= 1;
                counts[nums[left-1]] -= 1;
            }

            // handle right incoming number
            if(counts.find(nums[right]) != counts.end()) {
                if(counts[nums[right]] == 1)
                    anamolies += 1;
                counts[nums[right]] += 1;
            }
            else
                counts[nums[right]] = 1;

            
            // check if all numbers are distinct
            if(anamolies == 0)
                maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};