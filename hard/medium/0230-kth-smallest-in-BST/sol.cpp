#include <stack>
using namespace std;

class Solution {
private:
    stack<TreeNode*> st;
    TreeNode *ptr;

    TreeNode* goToLeftMostNode(TreeNode *ptr) {
        if(!ptr)    return nullptr;
        
        // traverse LNR - inorder fashion
        while(ptr->left) {
            st.push(ptr);
            ptr = ptr->left;
        } 

        return ptr;
    }

    void initialize(TreeNode *root) {
        ptr = goToLeftMostNode(root);
    }

    int smallest() {
        int returnValue = ptr->val;

        // check right node
        if(ptr->right) {
            ptr = goToLeftMostNode(ptr->right);
        }
        // go to parent else wise
        else {
            if(st.empty()) 
                ptr = nullptr;
            else {
                ptr = st.top();
                st.pop();
            }
        }

        return returnValue;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        initialize(root);

        for(int i=0;i<k-1;i+=1) 
            smallest();

        return smallest();
    }
};