class Solution:
    def maxOperations(self, s: str) -> int:
        ans = 0
        ones = 0

        for i in range(len(s)):
            if s[i] == '1':
                ones += 1
            elif i>0 and s[i-1] == '1':
                ans += ones

        return ans