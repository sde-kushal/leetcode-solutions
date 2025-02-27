#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> store;
        bool foundDouble = true;

        for(int i=0;i<bannedWords.size();i+=1)
            store.insert(bannedWords[i]);
        
        for(int i=0;i<message.size();i+=1) 
            if(store.count(message[i])) {
                foundDouble = !foundDouble;
                if(foundDouble)
                    return true;
            }

        return false;
    }
};