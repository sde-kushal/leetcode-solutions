#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string spacedString = "";
        int curr = 0;

        for(int i=0;i<s.size();i+=1) {
            if(curr<spaces.size() && i==spaces[curr]) {
                spacedString += ' ';
                curr += 1;
            }
            spacedString += s[i];
        }
        
        return spacedString;
    }
};