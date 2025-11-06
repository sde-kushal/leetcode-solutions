class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        prev = 0
        ans = None

        for num in arr:
            diff = num - prev - 1

            if diff < k:
                k -= diff
            else:
                ans = prev + k
                break

            prev = num


        if not ans:
            ans = prev + k

        return ans