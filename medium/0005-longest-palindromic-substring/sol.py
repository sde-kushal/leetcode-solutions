class Solution:
    def palindrome(self,s,l,r):
        count = 0

        while l>=0 and r<len(s) and s[l]==s[r]:
            if l == r:  count += 1
            else:       count += 2
            l -= 1
            r += 1

        return count



    def longestPalindrome(self, s: str) -> str:
        ans, max_len = "", 0

        for i in range(len(s)):
            odd = self.palindrome(s,i,i)
            eve = self.palindrome(s,i,i+1)

            if eve > max_len:
                max_len = eve
                start = i - eve//2 + 1
                end   = i + eve//2 + 1
                ans   = s[start:end]

            elif odd > max_len:
                max_len = odd
                start = i - (odd-1)//2
                end   = i + (odd-1)//2 + 1
                ans = s[start:end]


        return ans