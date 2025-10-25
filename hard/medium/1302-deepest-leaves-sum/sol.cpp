using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:    
    int maxDepth = -1, sum = 0;
    void traverseTree(TreeNode* ptr, int depth) {
        if(!ptr)    return;
        if(!ptr->left && !ptr->right) {
            if(maxDepth < depth+1) {
                maxDepth = depth+1;
                sum = ptr->val;
            }
            else if(maxDepth == depth+1) 
                sum += ptr->val;
            
            return;
        }
        
        traverseTree(ptr->left, depth+1);
        traverseTree(ptr->right, depth+1);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        traverseTree(root, 0);
        return sum;
    }
};
