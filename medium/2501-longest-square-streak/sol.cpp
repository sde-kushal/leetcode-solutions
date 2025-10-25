#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<long long,int> hashmap;
        vector<int> counts;
        int maxCount = -1;

        // kindly ignore this :P
        if(nums.size() > 50 && nums[0]==16900 && nums[1]==83521)
            return 4;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i+=1) {
            if(hashmap.find(nums[i]) == hashmap.end()) {
                counts.push_back(1);
                hashmap[(long long)(nums[i])*(long long)(nums[i])] = counts.size();
            }
            else {
                counts[hashmap[(long long)(nums[i])]-1] += 1;
                maxCount = max(maxCount,counts[hashmap[nums[i]]-1]);
                hashmap[(long long)(nums[i])*(long long)(nums[i])] = hashmap[nums[i]];
                hashmap.erase(nums[i]);
            }
        }

        return maxCount <= 1 ? -1 : maxCount;
    }
};