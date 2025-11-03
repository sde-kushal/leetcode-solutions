class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        l, r, n = 0, 1, len(colors)
        cost = 0

        while r < n:
            # keep traversing till consecutive colors are same
            localSum = neededTime[l]
            localMax = neededTime[l]
            while r < n and colors[r] == colors[l]:
                localSum += neededTime[r]
                localMax = max(neededTime[r], localMax)
                r += 1
            
            # only one balloon of same color in consecutive group
            if l == r or (r == n and l == n-1):
                continue
            
            # update cost and omit max time one
            cost += localSum - localMax
            l = r
            r += 1


        return cost
    