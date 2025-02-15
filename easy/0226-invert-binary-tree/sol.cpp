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
    TreeNode *traverse(TreeNode *ptr) {
        if (!ptr)
            return nullptr;
        traverse(ptr->left);
        traverse(ptr->right);

        if (ptr->left || ptr->right) {
            TreeNode *temp = ptr->right;
            ptr->right = ptr->left;
            ptr->left = temp;
        }

        return ptr;
    }

public:
    TreeNode *invertTree(TreeNode *root) {
        return traverse(root);
    }
};