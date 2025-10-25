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
    int total = 0;
    void recursiveSum(TreeNode* ptr, int sum) {
        if(!ptr)
            return;
        
        sum = sum*10 + ptr->val;
        
        if(!ptr->left && !ptr->right) {
            total += sum;    
            return;
        }

        recursiveSum(ptr->left, sum);
        recursiveSum(ptr->right, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        recursiveSum(root,0);
        return total;
    }
};