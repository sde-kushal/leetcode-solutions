#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        stack<string> st;
        string curr = "", simplified = "";

        for(int i=0;i<path.size();i+=1) {
            if(path[i]=='/') {
                if(curr==".." && !st.empty())
                    st.pop();
                else if(curr!="" && curr!="." && curr!="..") 
                    st.push(curr);
                curr = "";
            }
            else curr += path[i];
        }

        while(!st.empty()) {
            simplified = "/" + st.top() + simplified;
            st.pop();
        }

        return simplified == "" ? "/" : simplified;
    }
};