class Solution:
    def bin_search(self, potions:List[int], req:int, n:int) -> int:
        low, high = 0, n-1
        index = 0

        while low <= high:
            mid = low + int((high-low)/2)

            if potions[mid] >= req:
                high = mid-1
            else:
                if mid < high and potions[mid+1] >= req:
                    index = mid+1
                    break
                elif mid == high:
                    index = mid+1
                    break
                else:
                    low = mid+1
        

        return index



    
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        pairs = [0]*len(spells)
        n = len(potions)
        
        # sort potions
        potions = sorted(potions)

        # iterate over spells:
        for i, spell in enumerate(spells):
            # req_potion = ceil(success/spell)
            req_potion = math.ceil(success/spell)
            
            # binary search index
            index = self.bin_search(potions,req_potion,n)

            # store for this ith index
            pairs[i] = n - index



        return pairs