class Solution:
    def subpalindromes(self, s, l, r):
        count = 0
        while l>=0 and r<len(s) and s[l]==s[r]:
            l -= 1
            r += 1
            count += 1

        return count



    def countSubstrings(self, s: str) -> int:
        count = 0

        for i in range(len(s)):
            count += self.subpalindromes(s,i,i)
            count += self.subpalindromes(s,i,i+1)

        return count