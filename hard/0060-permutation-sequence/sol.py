class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        
        def permute(arr):
            # find breakpoint
            bkp = -1
            for i in range(n-2,-1,-1):
                if arr[i] < arr[i+1]:
                    bkp = i
                    break
            
            # if no breakpoint then reverse
            if bkp == -1:
                arr = arr[::-1]
                return 

            # find index > breakpoint from right
            for i in range(n-1,bkp,-1):
                if arr[i] > arr[bkp]:
                    index = i
                    break

            # swap
            arr[index], arr[bkp] = arr[bkp], arr[index]

            # reverse from breakpoint+1 .. n
            j = n-1
            for i in range(bkp+1, 1+ (n+bkp)//2):
                arr[i], arr[j] = arr[j], arr[i]
                j -= 1


        
        arr = [ x for x in range(1,n+1) ]
        
        for i in range(1,k):
            permute(arr)
        
        result = ""
        for num in arr:
            result += str(num)
        
        return result