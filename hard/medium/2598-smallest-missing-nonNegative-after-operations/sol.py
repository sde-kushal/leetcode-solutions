class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        buff = [0]*value
        mex = None
        looped, i = 0, 0

        # slot into buffer
        for num in nums:
            i = (num+value*1000_000_000) % value
            buff[i] += 1

        i = 0

        while True:
            # find MEX
            if buff[i] == 0:
                mex = i + looped*value
                break
            
            else:
                buff[i] -= 1
            
            # increase index
            if i == value-1:
                i = 0
                looped += 1
            else:
                i += 1

        return mex