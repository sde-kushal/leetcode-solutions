class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        beams = 0
        prev_count, curr_count = 0, 0

        for row in bank:
            for cell in row:
                if cell == '1':
                    curr_count += 1
            if prev_count > 0:
                beams += prev_count * curr_count
            if curr_count > 0:
                prev_count = curr_count
            curr_count = 0

        return beams