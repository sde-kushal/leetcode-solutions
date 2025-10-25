class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        NIL = -999
        
        def enc(arr):
            h = ""
            for num in arr:
                x = num + 200
                h += str(x)
            return h


        def fn(i, arr):
            # base case
            if i == len(nums):
                if len(arr) > 1: 
                    h = enc(arr)
                    if h not in seen:
                        ans.append(arr)
                        seen.add(h)
                return
            
            last = arr[-1] if len(arr) > 0 else NIL
            curr = nums[i]

            if last == NIL:
                fn(i+1,arr)         # skip
                fn(i+1,arr+[curr])  # take
            
            elif curr >= last:
                fn(i+1,arr)         # skip
                fn(i+1,arr+[curr])  # take
            
            else:
                fn(i+1,arr)         # skip

        
        ans = []
        seen = set()
        fn(0, [])

        return ans

