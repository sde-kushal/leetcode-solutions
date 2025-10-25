#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int totalShift = 0;
        for(int i=shifts.size()-1;i>=0;i--) {
            totalShift = (totalShift + shifts[i]) % 26;
            s[i] = (char)((static_cast<int>(s[i]) - 97 + totalShift) % 26 + 97);
        }

        return s;
    }
};