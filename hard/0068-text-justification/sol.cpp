#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
private:
    string generateSpaces(int total, int &extras) {
        string sp = "";
        for(int i=0;i<total;i+=1)
            sp += ' ';
        
        if(extras > 0) {
            sp += ' ';
            extras -= 1;
        }

        return sp;
    }

    string createJustified(vector<string> &words, int start, int end, int spaces, bool alignLeft, int &maxWidth) {
        string str = "";
        int space = spaces / (max(1,end-start));
        int extras = spaces % (max(1,end-start));

        for(int i=start;i<=end;i+=1) {
            str += words[i];
            if(i<end)
                str += alignLeft ? " " : generateSpaces(space,extras);
        }

        while(str.size() < maxWidth)
            str += ' ';
        
        return str;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justified;
        int buffer = 0, start = 0;

        for(int i=0;i<words.size();i+=1) {
            if(buffer + words[i].size() + i - start > maxWidth) {
                justified.push_back(createJustified(words,start,i-1,maxWidth-buffer,false,maxWidth));
                buffer = 0;
                start = i;
            }
            buffer += words[i].size();
        }

        justified.push_back(createJustified(words,start,words.size()-1,0,true,maxWidth));

        return justified;
    }
};