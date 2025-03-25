#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1,s2;

public:
    MyQueue() {
    }
    
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if(!s1.empty()) {
            int val = s1.top();
            s1.pop();
            return val;
        }
        return -1;
    }
    
    int peek() {
        if(!s1.empty())
            return s1.top();
        return -1;
    }
    
    bool empty() {
        return s1.empty();
    }
};