class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        prev = None
        ans = True

        for bit in bits:
            ans = False if prev else True
            prev = 0 if bit and prev else bit

        return ans