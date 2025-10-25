#include <string>
using namespace std;

class Solution {
private:
    string invertAndReverse(string s) {
        string edited = "";
        for(int i=s.size()-1;i>=0;i-=1)
            edited += s[i] == '0' ? '1' : '0';
        return edited;
    }

public:
    char findKthBit(int n, int k) {
        // len after n moves: 2^n - 1
        string s = "0";
        
        while(s.size() < k)
            s += "1" + invertAndReverse(s);
        
        return s[k-1];
    }
};