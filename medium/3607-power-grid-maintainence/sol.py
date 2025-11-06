import heapq

class Solution:
    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        
        def find(n):
            while dsu[n] != n:
                n = dsu[n]
            return n

        def connect(a,b):
            p1 = find(a)
            p2 = find(b)
            if p1 > p2: dsu[p1] = p2
            else:       dsu[p2] = p1
        
        
        result = []
        powers = [1]*c
        dsu = [x for x in range(c)]
        heapCache = dict()

        # build DSU
        for a,b in connections:
            connect(a-1,b-1)
        

        # build min heap for connected components
        for t in range(1,c+1):
            origin = find(t-1)
            if origin in heapCache:
                arr = heapCache[origin]
                heapq.heappush(arr,t-1)
            else:
                arr = []
                heapq.heappush(arr,t-1)
                heapCache[origin] = arr

        
        for q,t in queries:
            # check maintainence
            if q == 1:
                if powers[t-1]: result.append(t)
                else: 
                    origin = find(t-1)
                    arr = heapCache[origin]
                    node = 1+arr[0] if arr else -1
                    result.append(node)
            
            # turn node off
            elif q == 2:
                powers[t-1] = 0
                origin = find(t-1)
                arr = heapCache[origin]
                while arr and powers[arr[0]] == 0:
                    heapq.heappop(arr)
        

        return result
                    
