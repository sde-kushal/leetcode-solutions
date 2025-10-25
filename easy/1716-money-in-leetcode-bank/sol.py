class Solution:
    def totalMoney(self, n: int) -> int:
        k = n//7    # total weeks
        acc = int((7*k*(k+7))/2)

        rem = n%7   # non-complete week days
        a = k+1     # first term

        s = int((rem*(2*a+(rem-1)))/2)

        return s+acc