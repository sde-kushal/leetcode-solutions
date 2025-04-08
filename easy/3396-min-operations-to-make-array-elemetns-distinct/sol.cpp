#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> freq(101,0);
        int exceedingCount = 0;

        for(int i=0;i<nums.size();i+=1) {
            freq[nums[i]] += 1;
            if(freq[nums[i]] > 1)
                exceedingCount += 1;
        }

        // all elements are distinct initially
        if(!exceedingCount) return 0;
        
        // keep removing until exceedingCount = 0 or arr.empty()
        for(int i=0;i<nums.size();i+=3) {
            if(freq[nums[i]] > 1) {
                exceedingCount -= 1;
                freq[nums[i]] -= 1;
            }

            if(i+1 < nums.size() && freq[nums[i+1]] > 1) {
                exceedingCount -= 1;
                freq[nums[i+1]] -= 1;
            }

            if(i+2 < nums.size() && freq[nums[i+2]] > 1) {
                exceedingCount -= 1;
                freq[nums[i+2]] -= 1;
            }

            if(exceedingCount == 0)
                return i/3 + 1;
        }

        // will never reach this state
        return -1;
    }
};