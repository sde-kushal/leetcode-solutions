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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *leader = head;
        while(n>0) {
            // this case only exists if first element of LL is asked to be deleted
            if(!leader->next) {
                ListNode *temp = head;
                head = head->next;
                delete temp;
                return head;
            }

            leader = leader->next;
            n -= 1;
        }

        ListNode *follower = head;
        while(leader->next) {
            leader = leader->next;
            follower = follower->next;
        }

        ListNode *p = follower->next->next;
        ListNode *temp = follower->next;
        follower->next = p;
        delete temp;
        
        return head;
    }

};