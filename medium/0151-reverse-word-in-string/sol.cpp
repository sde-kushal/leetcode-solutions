#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        s = ' ' + s;
        bool addSpace = false;
        string temp = "", reversed = "";
        
        for(int i=s.size()-1;i>=0;i-=1) 
            if(s[i] == ' ') {
                if(temp.size() > 0) {
                    if(addSpace)    reversed += ' ';
                    else            addSpace = true;
                    reversed.append(temp);
                    temp = "";
                }
            }
            else  
                temp = s[i] + temp;
        
        return reversed;
    }
};