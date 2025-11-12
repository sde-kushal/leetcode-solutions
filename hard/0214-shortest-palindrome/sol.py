class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        lengths = [1 for _ in range(n)]
        st = []
        ans = 0

        # LENGTHS FROM LEFT TO INDEX
        for i in range(n):
            num = heights[i]
            
            if st and num <= heights[st[-1]]:
                while st and heights[st[-1]] >= num:
                    st.pop()
                lengths[i] = i-st[-1] if st else i+1
            
            st.append(i) 
        

        st = []

        # LENGTHS FROM RIGHT TO INDEX
        for i in range(n-1,-1,-1):
            num = heights[i]
            
            if st and num <= heights[st[-1]]:
                while st and heights[st[-1]] >= num:
                    st.pop()
                lengths[i] += (st[-1]-i-1) if st else (n-i-1)

            st.append(i)
            ans = max(ans, heights[i]*lengths[i])



        return ans