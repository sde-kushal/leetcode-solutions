class Solution:
    def merge(self, arr: List[List[int]]) -> List[List[int]]:
        arr.sort(key=lambda x:(x[0],x[1]))
        result = []
        currMax = arr[0][1]
        left = arr[0][0]

        for a,b in arr:
            if a > currMax:
                result.append([ left, currMax ])
                left = a
            currMax = max(currMax, b)

        result.append([ left, currMax ])
        return result