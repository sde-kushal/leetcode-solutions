class MyHashMap:

    def __init__(self):
        n = 10**3 + 1
        self.spaces = [[None for _ in range(n)] for _ in range(n)]
        self.MOD = n


    def getRowCol(self, key):
        return [key // self.MOD, key % self.MOD]
    

    def put(self, key: int, value: int) -> None:
        row, col = self.getRowCol(key)
        self.spaces[row][col] = value


    def get(self, key: int) -> int:
        row, col = self.getRowCol(key)
        val = self.spaces[row][col]
        return val if val != None else -1


    def remove(self, key: int) -> None:
        row, col = self.getRowCol(key)
        self.spaces[row][col] = None

