#include <queue>
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
    priority_queue<int> sizes;

    int checkPerfectSubtree(TreeNode* ptr) {
        if(!ptr)    return 0;
        if(!ptr->left && !ptr->right) {
            sizes.push(1);
            return 1;
        }

        int lCount = checkPerfectSubtree(ptr->left);
        int rCount = checkPerfectSubtree(ptr->right);

        if(lCount < 0 || rCount < 0 || lCount!=rCount)
            return -1;
        if((!ptr->left && ptr->right) || (ptr->left && !ptr->right))
            return -1;
        
        sizes.push(1+lCount+rCount);
        return 1+lCount+rCount;
    }

public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        checkPerfectSubtree(root);
        for(;k>1;k-=1)
            if(sizes.empty())   return -1;
            else                sizes.pop();
        
        return sizes.empty() ? -1 : sizes.top();
    }
};