#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> bag(dictionary.begin(),dictionary.end());
        string temp = "", replaced = "";
        sentence += " ";
               
        for(int i=0;i<sentence.size();i+=1) {
            if(sentence[i]==' ') {
                replaced += temp;
                if(i!=sentence.size()-1)
                    replaced += ' ';

                temp = "";
            }
            else {
                temp += sentence[i];
                if(bag.find(temp)!=bag.end()) {
                    while(sentence[i]!=' ')
                        i += 1;
                    i -= 1;        
                }
            }
        }

        return replaced;
    }
};