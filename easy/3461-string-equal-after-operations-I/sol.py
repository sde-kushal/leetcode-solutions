class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n = len(s)
        
        while n > 2:
            temp = ""
            
            for i in range(n-1):
                mod = (int(s[i]) + int(s[i+1])) % 10
                temp += str(mod)
            
            s = temp
            n = len(s)


        return True if s[0] == s[1] else False