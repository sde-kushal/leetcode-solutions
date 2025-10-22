class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.mem1, self.mem2 = {}, {}
        self.nums2 = nums2

        for i, num in enumerate(nums1):
            if num in self.mem1: self.mem1[num] += 1
            else: self.mem1[num] = 1
        
        for i, num in enumerate(nums2):
            if num in self.mem2: self.mem2[num] += 1
            else: self.mem2[num] = 1



    def add(self, index: int, val: int) -> None:
        oldNum = self.nums2[index]
        newNum = val + oldNum

        self.nums2[index] = newNum
        self.mem2[oldNum] -= 1

        if newNum in self.mem2: self.mem2[newNum] += 1
        else: self.mem2[newNum] = 1



    def count(self, tot: int) -> int:
        ans = 0

        for num in self.mem1.keys():
            if tot >= num and tot-num in self.mem2:
                ans += self.mem1[num]*self.mem2[tot-num]

        return ans
