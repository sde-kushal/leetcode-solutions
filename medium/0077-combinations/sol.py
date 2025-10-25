class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        def backtrack(prev, rem, comb_arr):
            if rem == 0:
                ans.append(comb_arr)
                return

            for num in range(prev+1, n-rem+2):
                backtrack(num, rem-1, comb_arr+[num])


        ans = []
        backtrack(0, k, [])
        
        return ans