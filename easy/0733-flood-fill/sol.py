class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] == color:
            return image

        start_color = image[sr][sc]
        queue = deque()
        m, n = len(image), len(image[0])
        
        queue.append((sr,sc))
        image[sr][sc] = color

        while queue:
            i, j = queue.popleft()

            if i>0 and image[i-1][j]==start_color:
                image[i-1][j] = color
                queue.append((i-1,j))
            if i<m-1 and image[i+1][j]==start_color:
                image[i+1][j] = color
                queue.append((i+1,j))

            if j>0 and image[i][j-1]==start_color:
                image[i][j-1] = color
                queue.append((i,j-1))
            if j<n-1 and image[i][j+1]==start_color:
                image[i][j+1] = color
                queue.append((i,j+1))
        

        return image