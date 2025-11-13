# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        ptr = head
        slow, fast = ptr, ptr

        while fast.next:
            slow = slow.next
            fast = fast.next
            if fast.next: fast = fast.next
        
        st = []
        
        temp = slow
        slow = slow.next
        temp.next = None

        while slow:
            temp = slow
            st.append(temp)
            slow = slow.next
            temp.next = None
        
        while st:
            temp = ptr.next
            ptr.next = st.pop()
            ptr = ptr.next
            ptr.next = temp
            ptr = ptr.next

        return head