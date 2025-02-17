using namespace std;

class Solution {
private:
    TreeNode *lca, *a, *b;
    int findLCA(TreeNode *ptr) {
        if(!ptr || lca) 
            return 0;
        
        int desc = findLCA(ptr->left) + findLCA(ptr->right);

        if(desc == 2 || ((ptr == a || ptr == b) && desc == 1)) {
            lca = ptr;
            return 0;
        }
        
        return (ptr == a || ptr == b ? 1 : 0) + desc;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        a = p;
        b = q;
        findLCA(root);
        return lca;
    }
};