using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        ListNode *prev = nullptr;

        while(fast && fast->next) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;

            if(fast && fast->next) 
                fast = fast->next;
        }
        
        if(!prev)
            return nullptr;

        prev->next = slow->next;
        slow->next = nullptr;

        return head;
    }
};