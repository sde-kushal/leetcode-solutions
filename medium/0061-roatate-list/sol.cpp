using namespace std;

class ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)   return nullptr;

        ListNode *curr = head;
        int offset = 0;
        while(curr) {
            curr = curr->next;
            offset += 1;
        }

        offset = k % offset;

        if(offset==0)
            return head;
        
        curr = head;
        offset -= 1;
        while(offset>0) {
            curr = curr->next;
            offset -= 1;
        }

        curr = curr->next;
        ListNode *prev = head;

        while(curr->next) {
            curr = curr->next;
            prev = prev->next;
        }

        curr->next = head;
        head = prev->next;
        prev->next = nullptr;

        return head;
    }
};