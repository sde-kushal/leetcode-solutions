class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        
        def find(x):
            while x != dsu[x]:
                x = dsu[x]
            return x

        
        def union(u,v):
            p1 = find(u)
            p2 = find(v)
            if p1 > p2: dsu[p1] = p2
            else:       dsu[p2] = p1
            
            return min(p1,p2), max(p1,p2)



        dsu = [x for x in range(n+1)]
        cache = dict()

        for u,v,d in roads:
            p1,p2 = union(u,v)
            d = min(d, cache.get(p2, float('inf')) )
            if p1 in cache:
                cache[p1] = min(cache[p1], d)
            else:
                cache[p1] = d
        
        
        cost = 0

        if find(n) == 1:
            cost = cache[1]
        
        return cost
