#include <unordered_set>
using namespace std;

class FindElements {
private:
    unordered_set<int> store;

    void recoverTree(TreeNode *ptr, int val) {
        if(!ptr) return;

        ptr->val = val;
        store.insert(val);

        if(ptr->left)
            recoverTree(ptr->left, 2*ptr->val + 1);
        if(ptr->right)
            recoverTree(ptr->right, 2*ptr->val + 2);
    }

public:
    FindElements(TreeNode* root) {
        recoverTree(root, 0);
    }
    
    bool find(int target) {
        return store.count(target);
    }
};
