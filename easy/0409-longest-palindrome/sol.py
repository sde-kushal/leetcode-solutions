class Solution:
    def longestPalindrome(self, s: str) -> int:
        # A-Z 0-25 and a-z 26-51
        f = [0 for _ in range(52)]

        for ch in s:
            i = ord(ch) - 65
            if i > 26: i -= 6     # for a-z
            f[i] += 1
        
        odd_taken = False
        ans = 0

        for val in f:
            # odd count
            if val&1:
                if not odd_taken: 
                    ans += val
                    odd_taken = True
                else:
                    ans += val-1
            
            # even count
            else:
                ans += val


        return ans