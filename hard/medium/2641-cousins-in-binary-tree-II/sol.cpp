#include <vector>
#include <queue>
#include <utility>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root)   
            return nullptr;
            
        TreeNode* ptr;
        vector<int> currSums, nextSums;
        queue<pair<TreeNode*,int>> Q;
        int count = 0, nextCount = 0;
        int currSum = 0, nextSum = 0;
        int key = 0, i = 0;

        Q.push({root,0});
        count = 1;
        currSum = root->val;
        currSums = { root->val };
        
        while(!Q.empty() || nextSum > 0) {
            if(count == 0) {
                count = nextCount;
                nextCount = 0;
                i = 0;

                currSum = nextSum;
                nextSum = 0;
                currSums = nextSums;
                nextSums = vector<int>();
            }
            else {
                ptr = Q.front().first;
                key = Q.front().second;
                Q.pop();
                count -= 1;

                ptr->val = currSum - currSums[key];

                int tempSum = 0;
                if(ptr->left) {
                    Q.push({ ptr->left, i });
                    tempSum += ptr->left->val;
                    nextCount += 1;
                }
                if(ptr->right) {
                    Q.push({ ptr->right, i });
                    tempSum += ptr->right->val;
                    nextCount += 1;
                }
                
                if(tempSum > 0) {
                    nextSum += tempSum;
                    nextSums.push_back(tempSum);
                    i += 1;
                }
            }
        }

        return root;
    }
};