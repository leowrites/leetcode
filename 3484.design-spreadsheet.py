#
# @lc app=leetcode id=3484 lang=python3
#
# [3484] Design Spreadsheet
#

# @lc code=start
class Spreadsheet:

    def __init__(self, rows: int):
        self.grid = [[0] * 26 for _ in range(rows)]
    
    def getCoord(self, cell):
        column = ord(cell[0]) - 65
        row = int(cell[1:]) - 1
        return row, column

    def setCell(self, cell: str, value: int) -> None:
        row, col = self.getCoord(cell)
        self.grid[row][col] = value

    def resetCell(self, cell: str) -> None:
        row, col = self.getCoord(cell)
        self.grid[row][col] = 0

    def getValue(self, formula: str) -> int:
        add_index = formula.find('+')
        x = formula[1:add_index]
        y = formula[add_index + 1:]
        if x[0].isalpha():
            row, col = self.getCoord(x)
            x = self.grid[row][col]
        else:
            x = int(x)
        if y[0].isalpha():
            row, col = self.getCoord(y)
            y = self.grid[row][col]
        else:
            y = int(y)
        return x + y


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)
# @lc code=end

