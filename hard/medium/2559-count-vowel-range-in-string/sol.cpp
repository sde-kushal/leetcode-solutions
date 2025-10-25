#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int hasEdgeVowels(string str) {
        char vowels[5] = {'a','e','i','o','u'};
        bool l = false, r = false;
        for(int i=0;i<5;i+=1) {
            l |= str[0]==vowels[i];
            r |= str[str.size()-1]==vowels[i];
        }
        return l&r ? 1 : 0;
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pre(words.size(),0), ans(queries.size(),0);
        
        for(int i=0;i<words.size();i+=1) 
            pre[i] = (i>0?pre[i-1]:0)+hasEdgeVowels(words[i]);

        for(int i=0;i<queries.size();i+=1) 
            ans[i] = pre[queries[i][1]] - (queries[i][0]-1 >= 0 ? pre[queries[i][0]-1] : 0);

        return ans;
    }
};