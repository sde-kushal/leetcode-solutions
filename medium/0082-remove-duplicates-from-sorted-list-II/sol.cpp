using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode *tail = head->val == head->next->val ? nullptr : new ListNode(head->val);
        ListNode *ptr = head;

        if(tail) 
            head = tail;

        while(ptr) {
            while(ptr->next && ptr->val == ptr->next->val)
                ptr = ptr->next;
    
            ptr = ptr->next;

            if(!ptr) {
                if(tail)
                    tail->next = nullptr;
                break;
            }

            if(ptr->next && ptr->val == ptr->next->val)
                continue;
    
            if(tail) {
                tail->next = ptr;
                tail = tail->next;
            }
            else {
                tail = ptr;
                head = tail;
            }
        }

        return !tail ? nullptr : head;
    
    }
};