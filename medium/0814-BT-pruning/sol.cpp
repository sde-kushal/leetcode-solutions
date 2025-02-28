using namespace std;

class Solution {
private:
    bool prune(TreeNode *ptr) {
        if(!ptr) return false;

        bool lv = prune(ptr->left);
        bool rv = prune(ptr->right);

        if(!ptr->val) {
            if(!lv && rv)       ptr->left = nullptr;
            else if(lv && !rv)  ptr->right = nullptr;
            
            return lv | rv | false;
        }
        else {
            if(!lv) ptr->left = nullptr;
            if(!rv) ptr->right = nullptr;
            return true;    
        }

        return false;
    }


public:
    TreeNode* pruneTree(TreeNode* root) {
        bool hasOnes = prune(root);
        return !hasOnes ? nullptr : root;
    }
};