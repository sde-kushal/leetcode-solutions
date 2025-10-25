#include <string>
using namespace std;

class Solution {
private:
    char binarySum(char a, char &carry) {
        if(a=='1' && carry=='1')
            carry = '1';
        if((a=='0' && carry=='0') || (a=='1' && carry=='1'))
            return '0';
        return '1';
    }

public:
    int numSteps(string s) {
        int steps = s.size() - 1;
        char carry = '0';
        for(int i=s.size()-1;i>=0;i-=1) {
            if(s[i]=='0' && carry=='0')
                continue;
            s[i] = binarySum(s[i],carry);
            if((s[i]=='1' && i!=0) || (i==0 && carry=='1')) {
                steps += 1;
                carry = '1';    
            }
        }

        return steps;
    }
};