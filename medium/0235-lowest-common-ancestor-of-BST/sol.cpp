using namespace std;

class Solution {
private:
    TreeNode *a, *b, *result;

    int traverse(TreeNode *ptr) {
        if(result || !ptr)  return 0;
        
        int lc = traverse(ptr->left);
        int rc = traverse(ptr->right);
        int anc = 0;

        if(ptr==a || ptr==b)    anc += 1;
        if(lc==1)               anc += 1;
        if(rc==1)               anc += 1;

        if(anc==2) {
            result = ptr;
            return 0;
        }

        return anc;
    }   

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        a = p;
        b = q;
        traverse(root);
        return result;
    }
};