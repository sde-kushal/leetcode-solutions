class Solution:   
    
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        def backtrack(rem, prev_used, used):
            if rem == 0:
                ans.append(used)
                return 

            for num in candidates:
                if num > rem:
                    break
                if num < prev_used:
                    continue
                updated = used[:]
                updated.append(num)
                backtrack(rem-num, num, updated)


        ans = []
        candidates = sorted(candidates)
        backtrack(target, -1, [])

        return ans