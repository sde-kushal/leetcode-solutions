class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        f = [0 for _ in range(26)]
        timeout = [0 for _ in range(26)]
        count = 0

        for task in tasks:
            i = ord(task)-65
            f[i] += 1
            count += 1
        
        ans = 0

        while count > 0:
            index = -1
            # check max freq char not on timeout
            for i in range(26):
                if timeout[i]: timeout[i] -= 1
                if f[i] and timeout[i] == 0 and (index == -1 or f[index] < f[i]):
                    index = i
            
            # if index then update timeout else NIL
            if index >= 0:
                f[index] -= 1
                timeout[index] = n+1
                count -= 1
            
            ans += 1

            
        return ans