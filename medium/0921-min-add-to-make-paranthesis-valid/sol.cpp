#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0, found = 0;

        for(int i=0;i<s.size();i+=1) {
            if(s[i]=='(') {
                found += 1;
                count += 1;
            }   
            else 
                if(found == 0)  
                    count += 1;
                else {
                    found -= 1;
                    count -= 1;
                }
        }

        return count;
    }
};