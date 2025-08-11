import math

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        recorded = []
        slow, fast = head, head
        count = 0

        # record till half the trail
        while fast != None:
            recorded.append(slow.val)
            slow = slow.next
            fast = fast.next
            count += 1
            
            if fast != None:
                fast = fast.next
                count += 1

        # gain back pointer index
        ptr = math.floor(count / 2) - 1

        # check palindrome
        while slow != None:
            if slow.val != recorded[ptr]:
                return False
            
            slow = slow.next
            ptr -= 1


        return True    
