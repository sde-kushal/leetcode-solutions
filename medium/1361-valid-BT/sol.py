class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        
        def find(x):
            while dsu[x] != x:
                x = dsu[x]
            return x
        

        def isUnionedElseUnion(u,v):
            p1 = find(u)
            p2 = find(v)
            if p1 == p2:    return True
            elif p1 > p2:   dsu[p1] = p2
            else:           dsu[p2] = p1



        NULL = -1
        visited = [False for _ in range(n)]
        dsu = [x for x in range(n)]
        ans = True


        # union and check cycles
        for u in range(n):
            left, right = leftChild[u], rightChild[u]

            if ((left != NULL and isUnionedElseUnion(u,left)) or 
                (right != NULL and isUnionedElseUnion(u,right))):
                ans = False
                break
            
            if left != NULL:    visited[left] = True
            if right != NULL:   visited[right] = True
        

        relax = True         # only one node should be head

        # check all nodes visited except head
        for v in visited:
            if not v:
                if relax:   relax &= False
                else:
                    ans = False
                    break
        

        return ans