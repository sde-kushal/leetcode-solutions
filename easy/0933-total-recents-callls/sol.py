class RecentCounter:
    class Node:
        def __init__(self, val):
            self.val = val
            self.next = None


    def __init__(self):
        self.front = self.rear = None
        self.pings = 0


    def ping(self, t: int) -> int:
        node = self.Node(t)
        if not self.rear:
            self.front = self.rear = node
        else:
            self.rear.next = node
            self.rear = node
        
        self.pings += 1

        # trim from left if needed
        lower_limit = t - 3000
        ptr = self.front
        while ptr.val < lower_limit:
            temp = ptr
            ptr = ptr.next
            self.pings -= 1
            del temp
        
        self.front = ptr
        return self.pings
