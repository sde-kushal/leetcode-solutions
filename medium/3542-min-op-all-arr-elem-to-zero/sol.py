from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        st = []
        ans = 0

        for num in nums:
            # fresh start
            if num == 0:
                st = []
            else:
                # new number so ans + 1
                if not st or num > st[-1]:
                    ans += 1
                    st.append(num)
                
                # pop and check stack
                elif num < st[-1]:
                    while st and st[-1] > num:
                        st.pop()
                    if not st or st[-1] < num:
                        ans += 1
                        st.append(num)
        

        return ans                    