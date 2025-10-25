#include <vector>
#include <cmath>
using namespace std;

class CustomStack {
private:
    vector<int> st;
    int top, size;

public:
    CustomStack(int maxSize) {
        st = vector<int>(maxSize);
        top = -1;
        size = maxSize;
    }
    
    void push(int x) {
        if(top<size-1) {
            top += 1;
            st[top] = x;
        }        
    }
    
    int pop() {
        if(top==-1)
            return -1;

        int popped = st[top];
        top -= 1;
        return popped;
    }
    
    void increment(int k, int val) {
        int limit = min(k,top+1);
        for(int i=0;i<limit;i+=1)
            st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */