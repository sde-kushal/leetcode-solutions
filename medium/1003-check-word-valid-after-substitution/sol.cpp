#include <string>
#include <stack>
using namespace std;

#define A false
#define AB true

class Solution {
public:
    bool isValid(string s) {
        stack<bool> st;

        for(int i=0;i<s.size();i+=1) {
            switch(s[i]) {
                case 'a':
                    st.push(A);
                    break;

                case 'b':
                    if(st.empty() || st.top()==AB)
                        return false;
                    st.pop();
                    st.push(AB);
                    break;

                case 'c':
                    if(st.empty() || st.top()==A)
                        return false;
                    st.pop();
            }
        }

        return st.empty();
    }
};