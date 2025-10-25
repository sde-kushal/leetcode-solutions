#include <string>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
    int getDigit(string num) {
        int n = 0;
        int i = num[0]=='-' ? 1 : 0;
        for(;i<num.size();i+=1)
            n = n*10 + static_cast<int>(num[i]) - 48;
        
        return n * (num[0]=='-' ? -1 : 1);
    }

    bool isNumber(string str) {
        if(str[0]=='-')
            return str[1] >= '0' && str[1] <= '9';
        return str[0] >= '0' && str[0] <= '9'; 
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a, b;

        for(int i=0;i<tokens.size();i+=1) {
            if(isNumber(tokens[i]))
                st.push(getDigit(tokens[i]));
            else {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();

                if(tokens[i]=="+")      st.push(b+a);
                else if(tokens[i]=="-") st.push(b-a);
                else if(tokens[i]=="*") st.push(b*a);
                else if(tokens[i]=="/") st.push(floor(b/a));
            }
        }

        return st.top();
    }
};