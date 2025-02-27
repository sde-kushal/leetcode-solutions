#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size())
            return false;
            
        vector<int> freqs(26,0);
        
        for(int i=0;i<magazine.size();i+=1)
            freqs[magazine[i]-'a'] += 1;
        
        for(int i=0;i<ransomNote.size();i+=1) {
            if(freqs[ransomNote[i]-'a'] == 0)
                return false;
            freqs[ransomNote[i]-'a'] -= 1;
        }

        return true;
    }
};