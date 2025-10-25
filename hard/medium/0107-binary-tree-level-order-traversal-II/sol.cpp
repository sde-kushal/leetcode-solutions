#include <vector>
#include <queue>
#include <stack>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};

        vector<int> lvlNodes;
        stack<vector<int>> st;
        queue<TreeNode*> Q;
        
        Q.push(root);
        int curr = 1, nxtLvl = 0, levels = 0;
        TreeNode *ptr;

        while(!Q.empty() || lvlNodes.size() > 0) {
            if(curr == 0) {
                st.push(lvlNodes);
                lvlNodes = vector<int>();
                levels += 1;
                
                curr = nxtLvl;
                nxtLvl = 0;
            }
            else {
                ptr = Q.front();
                Q.pop();
                curr -= 1;

                lvlNodes.push_back(ptr->val);
                if(ptr->left)   { Q.push(ptr->left); nxtLvl += 1; }
                if(ptr->right)  { Q.push(ptr->right); nxtLvl += 1; }
            }
        }

        vector<vector<int>> bottomUpLevels(levels,vector<int>());
        levels = 0;
        while(!st.empty()) {
            bottomUpLevels[levels] = st.top();
            st.pop();
            levels += 1;
        }

        return bottomUpLevels;
    }
};