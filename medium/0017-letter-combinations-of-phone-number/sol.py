class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        def letter_count(n): return 4 if int(n) == 7 or int(n) == 9 else 3

        def btn_letters(n):
            a, i = 97, 0
            
            if n <= 7:      i = (n-2)*3 + a
            elif n == 8:    i = 19 + a      # 4*3 + 4 + a
            else:           i = 22 + a      # 4*3 + 4 + 3 + a

            total = letter_count(n)
            return [chr(x+i) for x in range(total)]
        


        n = 1
        size = 0

        for ch in digits:
            count = letter_count(ch)
            n *= count
            size += 1
        
        result = ["" for _ in range(n)]


        k = 1

        for c in range(size-1,-1,-1):
            dig = int(digits[c])
            letters = btn_letters(dig)
            count = letter_count(dig)
            i = 0
            step = 0

            for j in range(n):
                result[j] = letters[i] + result[j]
                step += 1
                if step == k:
                    i = (i+1)%count
                    step = 0
            
            k *= count


        return result