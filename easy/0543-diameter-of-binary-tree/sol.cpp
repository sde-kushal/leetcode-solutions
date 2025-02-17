#include <cmath>
using namespace std;

class Solution {
private:
    int diameter = 0;

    int maxHeight(TreeNode *ptr) {
        if(!ptr) return 0;

        int leftSize = maxHeight(ptr->left);
        int rightSize = maxHeight(ptr->right);

        diameter = max(diameter, leftSize + rightSize);

        return 1 + max(leftSize,rightSize);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxHeight(root);    
        return diameter;
    }
};