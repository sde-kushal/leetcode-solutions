class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        numbers = set()
        for num in nums:
            numbers.add(num)
        
        left, right = None, head
        while right:
            # go to node not in numbers
            while right and right.val in numbers:
                right = right.next
            
            # if node = None 
            if not right:
                if left: left.next = None
                break
            # if node exists
            else:
                if left: left.next = right
                else: head = right
                left = right
            
            right = right.next
        

        return head