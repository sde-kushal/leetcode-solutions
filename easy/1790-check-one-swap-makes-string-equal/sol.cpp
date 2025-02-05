#include <string>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        bool hasPaired = false, swtch = false;
        char a, b;
        
        for(int i=0;i<s1.size();i+=1) {
            if(s1[i] != s2[i]) {
                if(hasPaired)
                    return false;
                else {
                    if(swtch && (a!=s2[i] || b!=s1[i]))
                        return false;

                    swtch = !swtch;

                    a = s1[i];
                    b = s2[i];
                    
                    if(!swtch)
                        hasPaired = true;
                }
            }
        }

        return !swtch;
    }
};