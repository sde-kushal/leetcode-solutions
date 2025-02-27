#include <string>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<string> store, aux;
        unordered_set<string> palindromes;
        int currSize = 1;

        store.insert("");

        for(int i=0;i<s.size();i+=1) {
            auto it = store.begin();
            for(;it!=store.end();it++) {
                if((*it).size() == 2 && (*it)[0] == s[i])
                    palindromes.insert((*it)+s[i]);
                else if((*it).size() < 2)
                    aux.insert((*it)+s[i]);
            }
            for(it=aux.begin();it!=aux.end();it++)
                store.insert(*it);
            aux.clear();
        }

        return palindromes.size();
    }
};