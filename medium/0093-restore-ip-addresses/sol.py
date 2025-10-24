class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n, ans = len(s), []

        if not 4 <= n <= 12:
            return ans
        
        def fn(i, last_used, ip, dots):
            if i == n:
                if dots == 4:   
                    ans.append(ip[:-1])
                return

            # check validity
            if dots == 4:                           
                return

            if last_used == "":
                # single digit
                added = s[i] + "."
                fn(i+1, "", ip+added, dots+1)
                # double/triple digit
                if s[i] != '0':  
                    fn(i+1, s[i], ip, dots)

            elif len(last_used) == 1:
                # double digit
                added = last_used + s[i] + "."
                fn(i+1, "", ip+added, dots+1)
                # triple digit
                if last_used == '1' or (last_used == '2' and int(s[i]) <= 5):
                    fn(i+1, last_used+s[i], ip, dots)
            
            # triple digit
            else:
                if int(last_used) != 25 or (int(last_used) == 25 and int(s[i]) <= 5):
                    added = last_used + s[i] + "." 
                    fn(i+1, "", ip+added, dots+1)
        


        fn(0, "", "", 0)
        return ans