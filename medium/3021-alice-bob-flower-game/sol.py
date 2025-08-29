class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        def evens(x):
            return int(x/2) if x%2==0 else int((x-1)/2)
        def odds(x):
            return int(x/2) if x%2==0 else 1+int((x-1)/2) 

        ans = evens(n)*odds(m) + evens(m)*odds(n)
        return ans
        