#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ORs = {0};
        int maxOR = 0, n, OR;

        for(int i=0;i<nums.size();i+=1) {
            n = ORs.size();
            for(int j=0;j<n;j+=1) {
                OR = ORs[j] | nums[i];
                ORs.push_back(OR);
                maxOR = max(maxOR,OR);
                if(freq.find(OR)==freq.end())   freq[OR] = 1;
                else                            freq[OR] += 1;
            }
        }

        return freq[maxOR];
    }
};