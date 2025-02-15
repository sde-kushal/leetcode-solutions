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
    int target;

    bool traverse(TreeNode *ptr, int currSum) {
        if (!ptr)
            return false;

        if (!ptr->left && !ptr->right)
            if (currSum + ptr->val == target)
                return true;
            else
                return false;

        bool leftResult = traverse(ptr->left, currSum + ptr->val);

        return !leftResult ? traverse(ptr->right, currSum + ptr->val) : true;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        target = targetSum;
        return traverse(root, 0);
    }
};