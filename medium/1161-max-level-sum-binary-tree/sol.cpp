#include <queue>
#include <limits.h>
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
    int maxLevelSum(TreeNode* root) {            
        int maxSum = INT_MIN, maximalLevel;    
        int count = 0, nextCount = 0;
        int currLevel = 1, currSum = 0;
        TreeNode *ptr; 
        queue<TreeNode*> Q;
        bool hasMore = false;

        Q.push(root);
        count = 1;

        while(!Q.empty() || hasMore) {
            if(count == 0) {
                if(currSum > maxSum) {
                    maxSum = currSum;
                    maximalLevel = currLevel;
                }
                count = nextCount;
                nextCount = 0;
                currSum = 0;
                currLevel += 1;
                hasMore = false;
            }
            else {
                ptr = Q.front();
                Q.pop();
                count -= 1;

                currSum += ptr->val;
                hasMore = true;

                if(ptr->left)   { Q.push(ptr->left); nextCount += 1; }
                if(ptr->right)  { Q.push(ptr->right); nextCount += 1; }
            }
        }
    
        return maximalLevel;    
    }
};
