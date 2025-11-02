class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        seen = set()
        ans = []
        n = 0

        for num in nums:
            if num in seen:
                ans.append(num)
                n += 1
            else:
                seen.add(num)
            if n == 2:
                break
        
        
        return ans