class Solution:
    def maximum69Number (self, num: int) -> int:
        pos, i = -1, 1
        n = num

        while num > 0:
            if num%10 == 6:
                pos = i
            
            num = int(num/10)
            i *= 10
        
        
        if pos > -1:
            n += pos*3
        
        return n