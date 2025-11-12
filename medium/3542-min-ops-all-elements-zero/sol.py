class Solution:
    def minOperations(self, nums: List[int]) -> int:
        st = []
        ans = 0

        for num in nums:
            if num == 0:
                st = []
            else:
                if not st or num > st[-1]:
                    ans += 1
                    st.append(num)
                
                elif num < st[-1]:
                    while st and st[-1] > num:
                        st.pop()
                    if not st or st[-1] < num:
                        ans += 1
                        st.append(num)
        

        return ans                    