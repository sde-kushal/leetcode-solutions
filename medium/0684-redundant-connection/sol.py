class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        
        def find(n):
            while dsu[n] != n:
                n = dsu[n]
            return n

        def update_dsu(x,y):
            a, b = find(x), find(y)
            if a < b:   dsu[b] = a 
            else:       dsu[a] = b



        n = len(edges)
        dsu = [x for x in range(n+1)]
        ans = None

        for a,b in edges:
            orig1 = find(a)
            orig2 = find(b)
            if orig1 == orig2:
                ans = [a,b]
                break
            else:
                update_dsu(a,b)
        

        return ans
