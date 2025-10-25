#include <string>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        if(s.size() == 1)
            return 0;

        int swaps = 0;
        long long minSteps = 0;

        for (int i = s.size() - 1; i >= 0; i-=1) 
            if(s[i] == '0') swaps += 1;
            else            minSteps += swaps;
    
        return minSteps;
    }
};