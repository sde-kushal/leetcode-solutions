class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        store = set()
        for num in nums:
            store.add(num)
        
        while original in store:
            original *= 2
        
        return original