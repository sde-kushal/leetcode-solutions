class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        ans = target[0]
        n = len(target)

        for i in range(1,n):
            if target[i]-target[i-1] > 0:
                ans += target[i]-target[i-1]

        return ans