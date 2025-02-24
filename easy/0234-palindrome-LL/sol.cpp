#include <stack>
using namespace std;

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head;
    stack<int> st;

    while(fast && fast->next) {
      fast = fast->next;
      st.push(slow->val);
      if(fast->next) {
        slow = slow->next;
        fast = fast->next;
      }
    }

    slow = slow->next;

    while(slow) {
      if(slow->val != st.top())
        return false;
      st.pop();
      slow = slow->next;
    }

    return true;
  }
};