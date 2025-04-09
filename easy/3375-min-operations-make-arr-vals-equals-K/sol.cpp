#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool> exists(101,false);
        int least = 101, unique = 0;

        for(int i=0;i<nums.size();i+=1) {
            if(!exists[nums[i]]) {
                unique += 1;
                exists[nums[i]] = 1;
                least = min(least,nums[i]);
            }
        }

        if(k > least) return -1;

        return unique - 1 + (k==least ? 0 : 1);
    }
};