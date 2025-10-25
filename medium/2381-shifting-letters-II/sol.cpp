#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> overall(s.size(), 0);
        string shiftedStr = "";

        for(int i=0;i<shifts.size();i+=1) 
            if(shifts[i][2] == 0) {
                overall[shifts[i][0]] = (overall[shifts[i][0]] - 1 + 26) % 26;
                if(shifts[i][1] + 1 < s.size())
                    overall[shifts[i][1] + 1] = (overall[shifts[i][1] + 1] + 1) % 26;
            }
            else {
                overall[shifts[i][0]] = (overall[shifts[i][0]] + 1) % 26;
                if(shifts[i][1] + 1 < s.size())
                    overall[shifts[i][1] + 1] = (overall[shifts[i][1] + 1] - 1 + 26) % 26;
            }
        
        for(int i=0;i<overall.size();i+=1) {
            if(i>0)
                overall[i] = (overall[i] + overall[i-1]) % 26;
            shiftedStr += (char)((static_cast<int>(s[i]) - 97 + overall[i]) % 26 + 97);
        }
        
        return shiftedStr;
    }
};