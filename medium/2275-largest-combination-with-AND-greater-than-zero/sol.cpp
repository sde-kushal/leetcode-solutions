#include <vector>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int largestNumber = candidates[0];
        for(int i=1;i<candidates.size();i+=1)
            largestNumber = max(largestNumber, candidates[i]);
          
        int n = 0, largestComb = 0;
        for(;largestNumber>0;largestNumber>>=1)
            n+=1;

        vector<int> binary(n, 0);
        
        for (int i = 0; i < candidates.size(); i += 1)
            for(int j=binary.size()-1;j>=0;j-=1) {
              binary[j] += (candidates[i]==0 || candidates[i]%2 == 0) ? 1 : 0;
              if(candidates[i] > 0)
                  candidates[i] >>= 1;
              if(i==candidates.size()-1 && candidates.size() - binary[j] > largestComb)
                  largestComb = candidates.size() - binary[j];
            }
        
        return largestComb;
    }
};