using namespace std;

class Solution {
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            if(!root)
                return new TreeNode(val);
            
            TreeNode *ptr = root;
    
            while(ptr) {
                // move to right
                if(ptr->val < val) {
                    if(ptr->right)  
                        ptr = ptr->right;
                    else {
                        ptr->right = new TreeNode(val);
                        break;
                    }
                }
                // move to left
                else {
                    if(ptr->left)  
                        ptr = ptr->left;
                    else {
                        ptr->left = new TreeNode(val);
                        break;
                    }
                }
            }
    
            return root;
        }
    };