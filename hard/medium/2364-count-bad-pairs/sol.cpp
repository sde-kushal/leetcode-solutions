#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  long long countBadPairs(vector<int>& nums) {
      unordered_map<int,int> store;
      long long badPairs = 0;

      for(int i=0;i<nums.size();i+=1) {
        nums[i] -= i;
        if(store.count(nums[i])) {
          badPairs += i - store[nums[i]];
          store[nums[i]] += 1;
        } else {
          badPairs += i;
          store[nums[i]] = 1;
        }
      }

      return badPairs;
  }
};