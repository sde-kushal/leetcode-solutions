#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int currLen = 0, maxLen = 0;
        unordered_map<char,int> lastFound;

        for(int i=0;i<s.size();i+=1) {
            if(lastFound.find(s[i])!=lastFound.end()) 
                currLen = min(currLen+1, i-lastFound[s[i]]);
            else 
                currLen += 1;
            
            maxLen = max(maxLen,currLen);
            lastFound[s[i]] = i;
        }

        return maxLen;
    }
};