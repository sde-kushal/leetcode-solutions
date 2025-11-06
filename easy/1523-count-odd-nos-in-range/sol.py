class Solution:
    def countOdds(self, low: int, high: int) -> int:
        n = high - low + 1
        if n & 1:   return (low&1) + (n-1)//2
        else:       return n//2