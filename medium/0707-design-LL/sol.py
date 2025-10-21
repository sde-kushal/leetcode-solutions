class MyLinkedList:
    class Node:
        def __init__(self, x):
            self.val = x
            self.prev = self.next = None



    def __init__(self):
        self.head = self.tail = None
        self.n = 0



    def get(self, index: int) -> int:
        if self.n == 0 or index >= self.n:
            return -1
        
        ptr = self.pointerAtIndex(index)
        return ptr.val

        

    def addAtHead(self, val: int) -> None:
        temp = self.newNode(val)

        if self.head:
            temp.next = self.head
            self.head.prev = temp
            self.head = temp
        else:
            self.head = self.tail = temp
        
        self.listSizeIncrease()

        

    def addAtTail(self, val: int) -> None:
        temp = self.newNode(val)

        if self.tail:
            self.tail.next = temp
            temp.prev = self.tail
            self.tail = temp
        else:
            self.head = self.tail = temp
        
        self.listSizeIncrease()

        

    def addAtIndex(self, index: int, val: int) -> None:
        if index == self.n:
            self.addAtTail(val)
        elif index == 0:
            self.addAtHead(val)
        elif index > self.n:
            return
        else:
            ptr = self.pointerAtIndex(index)
            temp = self.newNode(val)

            mem = ptr.prev
            ptr.prev = temp
            temp.next = ptr
            temp.prev = mem
            mem.next = temp

            self.listSizeIncrease()
        


    def deleteAtIndex(self, index: int) -> None:
        if index >= self.n:
            return
        
        ptr = self.pointerAtIndex(index)
        left, right = ptr.prev, ptr.next

        if left:
            left.next = right
        if right:
            right.prev = left

        if not left:
            self.head = right if right else None
        if not right:
            self.tail = left if left else None
        
        self.listSizeDecrease()



    # ====== HELPER FUNCTIONS ==============

    def pointerAtIndex(self, index: int) -> Node:
        # check which is closer, head or tail
        ptr = self.head if index <= (self.n-1)//2 else self.tail
        toR = True if index <= (self.n-1)//2 else False
        gap = index if toR else self.n-1-index

        for _ in range(gap):
            ptr = ptr.next if toR else ptr.prev
        
        return ptr

    def newNode(self, val):
        return self.Node(val)

    def listSizeIncrease(self):
        self.n += 1
    
    def listSizeDecrease(self):
        self.n = max(0, self.n - 1)