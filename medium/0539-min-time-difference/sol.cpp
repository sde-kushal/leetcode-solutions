#include <vector>
#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
private:
    int getMinutes(string str) {
        auto digit = [](char ch) { 
            return (static_cast<int>(ch)-48); 
        };
        
        int hrs = (digit(str[0])*10 + digit(str[1]))*60;
        int mins = digit(str[3])*10 + digit(str[4]); 
        return hrs+mins;
    }

public:
    int findMinDifference(vector<string>& timePoints) {
        int len = timePoints.size();
        vector<int> mins(len,-1);
        
        for(int i=0;i<len;i+=1)
            mins[i] = getMinutes(timePoints[i]);
        
        sort(mins.begin(),mins.end());

        int minDiff = mins[len-1]-mins[0];
        minDiff = min(minDiff, 24*60 - (mins[len-1]-mins[0]));

        for(int i=1; i<len; i+=1) {
            minDiff = min(minDiff, mins[i]-mins[i-1]);
            minDiff = min(minDiff, 24*60 - (mins[i]-mins[i-1]));
        }

        return minDiff;
    }
};