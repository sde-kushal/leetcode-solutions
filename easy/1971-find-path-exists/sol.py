class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        
        def find(x):
            while x != dsu[x]:
                x = dsu[x]
            return x
        

        def dsuUpdate(a,b):
            p1 = find(a)
            p2 = find(b)
            if p1 < p2: dsu[p2] = p1
            else:       dsu[p1] = p2

        
        def isConnected():
            return find(source) == find(destination)


        
        dsu = [x for x in range(n)]
        ans = True if source == destination else False

        for x,y in edges:
            dsuUpdate(x,y)
            if source == x or source == y or destination == x or destination == y:
                if isConnected():
                    ans = True
                    break
        
        if not ans and isConnected():
            ans = True

        return ans
