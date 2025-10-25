#include <queue>
using namespace std;

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        TreeNode *ptr;
        queue<TreeNode*> Q;
        priority_queue<long long> heap;
        long long sum = 0;
        int count = 0, newCount = 0, levels = 0;

        Q.push(root);
        count = 1;

        while(!Q.empty() || sum > 0) {
            if(count == 0) {
                heap.push(sum);
                levels += 1;
                sum = 0;
                count = newCount;
                newCount = 0;
            }
            else {
                ptr = Q.front();
                Q.pop();

                sum += ptr->val;

                if(ptr->left)   { Q.push(ptr->left); newCount += 1; }
                if(ptr->right)  { Q.push(ptr->right); newCount += 1; }
                count -= 1;
            }
        }
        if(levels < k)
          return -1;
        
        while(k-1 > 0) {
            heap.pop();
            k -= 1;
        }

        return heap.top();
    }
};