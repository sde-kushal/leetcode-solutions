class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        
        x,y,z = target
        target_num_found = [False for _ in range(3)]
        xorAll = 7   # 111 in binary

        for a,b,c in triplets:
            if a>x or b>y or c>z:
                continue
            if a==x and not target_num_found[0]:
                target_num_found[0] = True
                xorAll ^= 4
            if b==y and not target_num_found[1]:
                target_num_found[1] = True
                xorAll ^= 2
            if c==z and not target_num_found[2]:
                target_num_found[2] = True
                xorAll ^= 1
            if xorAll == 0:
                break
        

        return True if xorAll == 0 else False