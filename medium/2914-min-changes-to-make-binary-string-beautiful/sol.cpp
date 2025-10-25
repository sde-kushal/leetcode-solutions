#include <string>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int changes = 0;

        for(int i=1;i<s.size();i+=2) 
            if(s[i] != s[i-1])
                changes += 1;

        return changes;
    }
};