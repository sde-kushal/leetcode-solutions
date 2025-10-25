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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};

        vector<vector<int>> nodes;
        vector<int> levelItems;
        queue<TreeNode*> Q;
        Q.push(root);
        int count = 1, newCount = 0;
        TreeNode *ptr;

        while(!Q.empty() || levelItems.size() > 0) {
            if(count == 0) {
                nodes.push_back(levelItems);
                levelItems = vector<int>();
                count = newCount;
                newCount = 0;
            }
            else {
                ptr = Q.front();
                Q.pop();
                count -= 1;

                levelItems.push_back(ptr->val);
                if(ptr->left)   { Q.push(ptr->left); newCount += 1; }
                if(ptr->right)  { Q.push(ptr->right); newCount += 1; }
            }
        }

        return nodes;
    }
};