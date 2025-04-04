#include <algorithm>
using namespace std;

class Solution {
private:
    TreeNode *LCA;
    int maxDepth;

    int solveByDepth(TreeNode *ptr, int depth) {
        if(!ptr) return depth;
        int leftMaxDepth = solveByDepth(ptr->left, depth+1);
        int rightMaxDepth = solveByDepth(ptr->right, depth+1);
        if(leftMaxDepth == rightMaxDepth && leftMaxDepth >= maxDepth) {
            maxDepth = leftMaxDepth;
            LCA = ptr;
        }
        return max(leftMaxDepth, rightMaxDepth);
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        LCA = nullptr;
        maxDepth = 0;
        
        solveByDepth(root, 0);
        return LCA;        
    }
};