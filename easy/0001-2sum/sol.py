class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        expected = {}
        pair = []

        for i, num in enumerate(nums):
            if num in expected:
                j = expected.get(num)
                pair = [i,j]
                break

            else:
                expected[target-num] = i        

        return pair