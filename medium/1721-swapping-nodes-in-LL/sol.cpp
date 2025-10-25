using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left = head, *right = head;
        ListNode *record;

        for( ; k>1; k-=1)
            right = right->next;

        record = right;

        while(right->next) {
            right = right->next;
            left = left->next;
        }

        if(left->val != record->val) {
            left->val ^= record->val;
            record->val ^= left->val;
            left->val ^= record->val;
        }

        return head;
    }
};