class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        pre = [0]*n
        pre[0] = arr[0]

        for i in range(1,n):
            pre[i] = pre[i-1] + arr[i]
        
        ans = pre[-1]
        k = 3

        for k in range(3,n+1,2):
            for i in range(n-k+1):
                j = i+k-1
                prev = 0 if i==0 else pre[i-1]
                ans += pre[j] - prev


        return ans