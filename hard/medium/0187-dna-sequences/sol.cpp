#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            if(s.size() <= 10)
                return {};
    
            vector<string> ans;
            unordered_map<string,int> seq;
            string curr = s.substr(0,10);
    
            seq[curr] = 1;
    
            for(int i=10;i<s.size();i+=1) {
                curr = curr.substr(1,9) + s[i];
    
                if(!seq.count(curr))    seq[curr] = 1;
                else if(seq[curr] <= 2) seq[curr] += 1;
                
                if(seq[curr] == 2) 
                    ans.push_back(curr);
            }
    
            return ans;
        }
    };