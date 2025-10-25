#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> hash;
        int count = 0;

        for(int i=1;i<nums.size();i+=1) {
          for(int j=i-1;j>=0;j-=1) {
            int currProd = nums[i] * nums[j];
            count += hash[currProd];
            hash[currProd] += 1;
          }
        }

        return count * 8;
    }
};