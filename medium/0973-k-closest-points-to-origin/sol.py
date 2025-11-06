import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        ans = []

        for x,y in points:
            d = x**2 + y**2
            heapq.heappush(heap,(d,x,y))
        
        for _ in range(k):
            d,x,y = heapq.heappop(heap)
            ans.append([x,y])
        
        return ans