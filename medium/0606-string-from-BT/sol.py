class Solution:
    
    def preorder(self, ptr):
        if not ptr:
            return ''

        nodeStr  = str(ptr.val)

        right = self.preorder(ptr.right)
        rightStr = '' if right == '' else '('+right+')'

        left  = self.preorder(ptr.left)
        leftStr = '' if left == right == '' else '('+left+')'
        

        return nodeStr + leftStr + rightStr


    
    def tree2str(self, root: Optional[TreeNode]) -> str:
        return self.preorder(root)