#include <stack>
using namespace std;

class BSTIterator {
private:
    stack<TreeNode*> st;
    TreeNode *ptr;

    void goToLeftMostNode(TreeNode *head) {
        ptr = head;    
        while(ptr->left) {
            st.push(ptr);
            ptr = ptr->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        goToLeftMostNode(root);
    }
    
    int next() {
        int nodeValue = ptr->val;

        // traverse right child just like during initialization
        if(ptr->right) {
            goToLeftMostNode(ptr->right);
        } 
        // go back to parent node
        else {
            if(!st.empty()) {
                ptr = st.top();
                st.pop();
            } else {
                ptr = nullptr; 
            } 
        }

        return nodeValue;
    }
    
    bool hasNext() {
        if(!ptr)
            return false;

        if(ptr->right || !st.empty())
            return true;
        
        return ptr != nullptr;
    }
};