class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: x[1], reverse=True)
        units = 0

        for i in range(len(boxTypes)):
            if truckSize == 0: break
            units += min(truckSize, boxTypes[i][0])*boxTypes[i][1]
            truckSize = max(0, truckSize-boxTypes[i][0])

        return units