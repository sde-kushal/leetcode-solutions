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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return nullptr;
        
        ListNode *left = head,
                 *right = head->next,
                 *prev = nullptr;
        
        if(right)   head = right;
        
        while(right) {
            left->next = right->next;
            right->next = left;
            if(prev)
                prev->next = right;
            
            prev = left;
            if(left->next)  right = left->next->next;
            else            right = nullptr;
            left = left->next;
        }

        return head;
    }
};