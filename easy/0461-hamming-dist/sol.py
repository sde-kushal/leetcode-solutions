class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        n = x ^ y
        dist = 0

        while n > 0:
            if n & 1:   dist += 1
            n >>= 1

        return dist