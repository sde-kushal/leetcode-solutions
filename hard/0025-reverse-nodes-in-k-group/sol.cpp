using namespace std;

class Solution {
private:
    ListNode *curr, *tail;
    ListNode *prev, *trail;

    // reverse node
    ListNode * reverseList(int &k) {
        ListNode *temp;
        for(int i=0;i<k;i+=1) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        tail->next = curr;
        if(trail) trail->next = prev;

        // store the starting node to return it
        temp = prev;

        // update for next iteration
        trail = tail;
        tail = curr;
        prev = trail;

        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // find total count
        int n = 0, blocks = 0;
        ListNode *ptr = head;
        while(ptr) {
            n += 1;
            ptr = ptr->next;
        }

        // get how many iterations to reverse node in k-group
        blocks = n/k;

        // iterate over total count    
        curr = tail = head;
        prev = trail = nullptr;

        for(int step = 0; step < blocks; step+=1) {
            if(step == 0) head = reverseList(k);
            else reverseList(k);
        }

        // return head
        return head;
    }
};