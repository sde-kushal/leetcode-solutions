#include <stack>
#include <string>
using namespace std;

class BrowserHistory {
stack<string> history, aux;

public:
    BrowserHistory(string homepage) {
        history.push(homepage);        
    }
    
    void visit(string url) {
        history.push(url);
        while(!aux.empty())
            aux.pop();
    }
    
    string back(int steps) {
        for(int i=0;i<steps;i+=1) {
            if(!history.empty()) {
                aux.push(history.top());
                history.pop();
            }
            else    break;
        }

        if(history.empty()) {
            history.push(aux.top());
            aux.pop();
        }

        return history.top();
    }
    
    string forward(int steps) {
        for(int i=0;i<steps;i+=1) {
            if(!aux.empty()) {
                history.push(aux.top());
                aux.pop();
            }
            else    break;
        }

        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */