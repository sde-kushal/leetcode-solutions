from collections import deque

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        l, r = -1, 0
        ans, prev_sum = 0, 0
        n, count = len(nums), 0
        q = deque()

        while r <= n:
            if r == n or nums[r] == 0:
                ans = max(ans, r-l-1+prev_sum)
                
                if k > 0:
                    prev_sum = prev_sum + r-l
                    if count >= k:
                        prev_sum -= q.popleft()

                    q.append(r-l)
                    count += 1
                    
                l = r
            
            r += 1

        
        return ans