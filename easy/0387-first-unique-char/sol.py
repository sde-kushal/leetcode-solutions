class Solution:
    def firstUniqChar(self, s: str) -> int:
        freq = [-1]*26

        for i in range(len(s)):
            j = ord(s[i]) - 97
            
            # found earlier
            if freq[j] >= 0:
                freq[j] = -2

            # update first occurence
            elif freq[j] == -1:
                freq[j] = i
        

        # find least index
        INF = float('inf')
        ans = INF
        
        for f in freq:
            if f >= 0:
                ans = min(ans, f)
        
        return ans if ans != INF else -1