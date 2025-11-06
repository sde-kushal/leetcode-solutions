"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        
        ptr = head
        copy_head, copy_ptr = None, None
        step = 0

        copy_ptrs = []

        while ptr:
            if not copy_head: 
                copy_head = Node(ptr.val)
                copy_ptr = copy_head
            else: 
                temp = Node(ptr.val)
                copy_ptr.next = temp
                copy_ptr = copy_ptr.next
            
            copy_ptrs.append(copy_ptr)
            ptr.val = ptr.val*1000 + step
            step += 1
            ptr = ptr.next
        

        ptr = head
        copy_ptr = copy_head

        while ptr:
            if ptr.random:
                if ptr.random.val == ptr.val:
                    copy_ptr.random = copy_ptr
                else:
                    i = ptr.random.val % 1000
                    copy_ptr.random = copy_ptrs[i]

            ptr = ptr.next
            copy_ptr = copy_ptr.next

        
        return copy_head