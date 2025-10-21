import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.heap = nums
        self.extra = False if len(nums) >= k else True
        heapq.heapify(self.heap)
        if not self.extra:
            for _ in range(len(nums)-k):
                heapq.heappop(self.heap)


    def add(self, val: int) -> int:
        top = self.heap[0] if self.heap else None
        if (top != None and val > top) or not top:
            heapq.heappush(self.heap, val)
            if not self.extra:
                heapq.heappop(self.heap)
            else:
                self.extra = False
            top = self.heap[0] if self.heap else None

        return top

