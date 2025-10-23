class MapSum:
    class Trie:
        def __init__(self, val):
            self.val = val
            self.link = [None]*26


    def __init__(self):
        self.head = self.Trie(-1)
        self.seen = {}



    def insert(self, key: str, val: int) -> None:
        diff = 0

        if key in self.seen:
            diff = val - self.seen[key]
            if diff == 0:
                return
        else:
            diff = val

        # update memory
        self.seen[key] = val
        
        # update trie
        ptr = self.head
        for ch in key:
            i = ord(ch) - 97
            if not ptr.link[i]:
                ptr.link[i] = self.Trie(val)
                ptr = ptr.link[i]
            else:
                ptr = ptr.link[i]
                ptr.val += diff



    def sum(self, prefix: str) -> int:
        ptr = self.head
        ans = 0

        for ch in prefix:
            i = ord(ch) - 97
            ptr = ptr.link[i]

            if not ptr:
                ans = 0
                break
                
            ans = ptr.val

        return ans
        