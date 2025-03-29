#include <unordered_map>
#include <vector>
using namespace std;

class FreqStack {
private:
    struct Node {
        vector<int> st;
        Node *left, *right;
        Node(): st({}), left(nullptr), right(nullptr) {};
    };
    unordered_map<int,Node*> mp;
    Node *head, *tail;

public:
    FreqStack() {
        head = tail = nullptr;
    }
    
    void push(int val) {
        // update existing data
        if(mp.find(val)!=mp.end()) {
            Node *curr = mp[val];
            if(curr==head) {
                Node *newNode = new Node();
                head->right = newNode;
                newNode->left = head;
                head = newNode;
                head->st.push_back(val);
                mp[val] = head;
            }
            else {
                curr = curr->right;
                curr->st.push_back(val);
                mp[val] = curr;
            }
        }

        // add new data
        else {
            if(!tail) {
                tail = new Node();
                head = tail;
            }
            tail->st.push_back(val);
            mp[val] = tail;
        }
    }
    
    int pop() {
        int top = head->st[head->st.size()-1];
        head->st.pop_back();
        
        mp[top] = head->left;
        if(!mp[top]) mp.erase(top);

        if(head->st.size()==0) {
            Node *temp = head;
            if(!head->left) head = nullptr;
            else {
                head = head->left;
                head->right->left = nullptr;
                head->right = nullptr;
            }
            delete temp;
        }
        
        return top;
    }
};
