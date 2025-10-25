#include <vector>
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
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};

        vector<int> rightView;
        queue<TreeNode*> Q;
        TreeNode *ptr;

        Q.push(root);
        int curr = 1, nxtLvl = 0, rightmost;

        while(!Q.empty()) {
            if(curr == 0) {
                rightView.push_back(rightmost);
                curr = nxtLvl;
                nxtLvl = 0;
            }
            else {
                ptr = Q.front();
                Q.pop();

                if(curr == 1)
                    rightmost = ptr->val;

                curr -= 1;

                if(ptr->left)   { Q.push(ptr->left); nxtLvl += 1; }
                if(ptr->right)  { Q.push(ptr->right); nxtLvl += 1; }
            }
        }

        rightView.push_back(rightmost);
        return rightView;
    }
};