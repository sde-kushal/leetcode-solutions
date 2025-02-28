#include <limits.h>
#include <cmath>
using namespace std;

class Solution {
private:
    int minDep;
    
    void findDepth(TreeNode *ptr, int curr) {
        if(!ptr->left && !ptr->right) {
            minDep = min(minDep,curr);
            return;
        }

        if(ptr->left)   findDepth(ptr->left,curr+1);
        if(ptr->right)  findDepth(ptr->right,curr+1);
    }
    
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        minDep = INT_MAX;
        findDepth(root, 1);
        return minDep;
    }
};