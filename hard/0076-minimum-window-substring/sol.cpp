#include <string>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
private:
    vector<int> f;
    vector<bool> exists;
    
    int getIndex(char ch) {
        int ascii = static_cast<int>(ch);
        return ascii < 97 ? ascii-65+26 : ascii-97; // [a-z, A-Z]
    }

    bool allCharactersCovered() {
        for(int i=0;i<52;i+=1)
            if(f[i] < 0) return false;
        return true;
    }

    string generateSubstring(string &s, int &left, int &right) {
        string str = "";
        for(int i=left;i<=right;i+=1)
            str += s[i];
        return str;
    }

public:
    Solution(): f(52,0), exists(52,false) {}

    string minWindow(string s, string t) {
        int index;

        // store chars of t
        for(int i=0;i<t.size();i+=1) {
            index = getIndex(t[i]);
            f[index] -= 1;
            exists[index] = true;
        }
        
        int left = 0, right = 0;
        int minWindow = INT_MAX;
        string minString = "";
        
        // find unoptimized substring
        for(;right<s.size();right+=1) {
            // keep expanding until all chars are consumed
            index = getIndex(s[right]);
            if(exists[index]) {
                f[index] += 1;
                if(allCharactersCovered()) {
                    // trim from left, update left
                    while(true) {
                        index = getIndex(s[left]);
                        if(exists[index] && f[index] > 0) {
                            left += 1;
                            f[index] -= 1;
                        }
                        else if(!exists[index])
                            left += 1;
                        else break;
                    }

                    if(right-left+1 < minWindow) {
                        minWindow = right-left+1;
                        minString = generateSubstring(s,left,right);
                    }
                }
            }
        }

        return minString;
    }
};