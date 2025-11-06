class Solution:

    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        ptr = root
        result = None

        while ptr:
            if not ptr:         break

            if ptr.val == val:
                result = ptr
                break

            if val < ptr.val:   ptr = ptr.left
            else:               ptr = ptr.right


        return result