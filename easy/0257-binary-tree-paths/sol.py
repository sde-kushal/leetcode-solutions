from collections import deque

class Solution:

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        stack = []
        queue = deque()
        queue.append((root, ""))
        DELIMITER = '->'

        result = []

        # DFS method to traverse paths -------
        while queue or stack:
            if not queue:
                queue.append(stack.pop())

            ptr, curr = queue.popleft()
            curr += str(ptr.val)

            if ptr.left or ptr.right:
                if ptr.left and ptr.right:
                    stack.append((ptr.right, curr+DELIMITER))
                
                node = ptr.left if ptr.left else ptr.right
                queue.append((node, curr+DELIMITER))

            else:
                result.append(curr)

        
        return result