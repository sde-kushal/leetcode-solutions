class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        # 2nd arr doesnt exist
        if n == 0:
            pass
        
        a, b = 0, 0

        # do until 2nd arr is empty
        while n > 0:
            # if first arr empty then simply put in
            if m == 0:
                nums1[a] = nums2[b]
                n -= 1
                a += 1
                b += 1
            

            else:
                # 1st arr pointer has less value, iterate to next
                if nums1[a] < nums2[b]:
                    a += 1
                    m -= 1
                
                else:
                    # push one place ahead each element in nums1
                    for i in range(a+m-1,a-1,-1):
                        nums1[i+1] = nums1[i]

                    # put 2nd arr val into new position
                    nums1[a] = nums2[b]
                    a += 1
                    b += 1
                    n -= 1