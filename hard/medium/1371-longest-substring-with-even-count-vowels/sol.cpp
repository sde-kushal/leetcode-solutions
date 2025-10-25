#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> cases(32,-2);
        cases[0] = -1;
        int longest = 0,
            prevSimilar = 0,
            mask = 0;

        for(int i=0;i<s.size();i++) {
            if(s[i]=='a')       mask ^= 16;
            else if(s[i]=='e')  mask ^= 8;
            else if(s[i]=='i')  mask ^= 4;
            else if(s[i]=='o')  mask ^= 2;
            else if(s[i]=='u')  mask ^= 1;

            prevSimilar = cases[mask];
            if(prevSimilar==-2)
                cases[mask] = i;
            else
                longest = max(longest,i-prevSimilar);
        }

        return longest;
    }
};