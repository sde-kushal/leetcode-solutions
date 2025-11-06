class Solution:
    def reverseWords(self, s: str) -> str:
        word = ""
        rev = ""
        SPACE = " "
        n = len(s)

        for i in range(n+1):
            ch = s[i] if i != n else SPACE

            if ch == SPACE:
                if word != "":
                    rev += word
                    word = ""
                if i != n:
                    rev += SPACE
            
            else:
                word = ch + word
        

        return rev