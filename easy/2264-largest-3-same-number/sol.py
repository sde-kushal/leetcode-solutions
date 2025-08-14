class Solution:
    def is_good(self, num: str):
        return num[0] == num[1] and num[1] == num[2]

    def largestGoodInteger(self, num: str) -> str:
        curr_score = num[0:3]
        
        max_score = -1
        if self.is_good(curr_score):
            max_score = int(curr_score)


        for left in range(1, len(num)-2):
            right = left + 2
            curr_score = curr_score[1:] + num[right]

            if self.is_good(curr_score):
                max_score = max(max_score, int(curr_score))


        if max_score == -1:
            return ""
        if max_score == 0:
            return "000"
        return str(max_score)