#include <queue>
#include <cmath>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   
            return nullptr;

        int depth = 0, index = 0;
        Node *ptr;   
        queue<Node*> Q;

        Q.push(root);
        
        while(!Q.empty()) {
            ptr = Q.front();
            Q.pop();

            if(index < pow(2,depth)-1) {
                ptr->next = Q.front();
                index += 1;
            }
            else {
                index = 0;
                depth += 1;
            }

            if(ptr->left)   Q.push(ptr->left);
            if(ptr->right)  Q.push(ptr->right);
        }

        return root;
    }
};