#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution {
private:
    unordered_map<int,int> counts;
    vector<int> nums;
    int maxSum;

    int nodeSum(TreeNode *ptr) {
        if(!ptr) return 0;
        int sum = ptr->val + nodeSum(ptr->left) + nodeSum(ptr->right);
        
        if(counts.count(sum))   counts[sum] += 1;
        else                    counts[sum] = 1;
        
        if(counts[sum] == maxSum)   
            nums.push_back(sum);
        else if(counts[sum] > maxSum) {
            nums = { sum };
            maxSum = counts[sum];
        }
        
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxSum = INT_MIN;
        nodeSum(root);
        return nums;
    }
};