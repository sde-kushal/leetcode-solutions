#include <string>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        int pendingDigits = 0;
        string cleared = "";

        for(int i=s.size()-1;i>=0;i-=1) {
            if(s[i]>='0' && s[i]<='9')
                pendingDigits += 1;
            else {
                if(pendingDigits > 0)
                    pendingDigits -= 1;
                else
                    cleared = s[i] + cleared;
            }
        }

        return cleared;
    }
};