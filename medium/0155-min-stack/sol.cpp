#include <stack>
#include <utility>
using namespace std;

class MinStack {
public:
    int topIndex;
    stack<pair<int,int>> st;

    MinStack() {
        topIndex = -1;
    }
    
    void push(int val) {
        int curr_min = val;
        if(topIndex > -1)
            curr_min = min(val,st.top().second);

        st.push(make_pair(val,curr_min));
        topIndex += 1;
    }
    
    void pop() {
        if(topIndex==-1) return;
        st.pop();
        topIndex -= 1;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};