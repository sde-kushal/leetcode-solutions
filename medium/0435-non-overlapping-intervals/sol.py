class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x:(x[0],x[1]))
        ans = 0
        prev = float('-inf')

        for a,b in intervals:
            if a < prev:
                ans += 1
                if b < prev: prev = b
            else:
                prev = b

        return ans