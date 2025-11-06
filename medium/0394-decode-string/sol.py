class Solution:
    def decodeString(self, s: str) -> str:
        word = ""
        count = 0
        st = []

        for ch in s:
            if ch == '[':
                st.append(word)
                st.append(max(1,count))
                word = ""
                count = 0
            
            elif ch == ']':
                times = st.pop()
                temp = st.pop() + word*times
                word = temp
            
            else:
                asci = ord(ch)
                if 48 <= asci <= 57:
                    count = count*10 + int(ch)
                else:
                    word += ch

        
        return word