using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int gcd(int a, int b) {
        if(a==0)    return b;
        if(b==0)    return a;
        if(a > b)   return gcd(a%b,b);
        return gcd(a,b%a);
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *front = head, *back = head;
        while(front->next) {
            front = front->next;
            int gcd_val = gcd(front->val,back->val);
            ListNode* temp = new ListNode(gcd_val, front);
            back->next = temp;
            back = back->next->next;
        }

        return head;
    }
};