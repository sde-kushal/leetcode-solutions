class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:

        def hasWinner():
            winner = -1
            if grid[0][0] == grid[0][1] == grid[0][2] != None:      winner = grid[0][0]
            elif grid[2][0] == grid[2][1] == grid[2][2] != None:    winner = grid[2][0]
            elif grid[1][0] == grid[1][1] == grid[1][2] != None:    winner = grid[1][0]
            elif grid[0][0] == grid[1][0] == grid[2][0] != None:    winner = grid[0][0]
            elif grid[0][1] == grid[1][1] == grid[2][1] != None:    winner = grid[0][1]
            elif grid[0][2] == grid[1][2] == grid[2][2] != None:    winner = grid[0][2]
            elif grid[0][0] == grid[1][1] == grid[2][2] != None:    winner = grid[0][0]
            elif grid[0][2] == grid[1][1] == grid[2][0] != None:    winner = grid[0][2]
            return winner


        RESULTS = ["A","B","Draw"]
        result = -1

        grid = [[None for _ in range(3)] for _ in range(3)]
        player = 0
        step = 0

        for x,y in moves:
            grid[x][y] = player
            player ^= 1
            step += 1

            if step >= 5:
                winner = hasWinner()
                if winner == 0 or winner == 1:
                    result = winner
                    break
        

        if step < 9:
            RESULTS[2] = "Pending"

        return RESULTS[result]