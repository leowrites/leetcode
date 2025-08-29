#
# @lc app=leetcode id=36 lang=python3
#
# [36] Valid Sudoku
#

# @lc code=start
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows, cols = len(board), len(board[0])
        def checkValid(curr, i, j):
            if board[i][j] == ".":
                return True
            if board[i][j] in curr:
                return False
            curr.add(board[i][j])
            return True

        # check rows
        for i in range(rows):
            curr = set()
            for j in range(cols):
                if not checkValid(curr, i, j):
                    return False

        # check cols
        for j in range(cols):
            curr = set()
            for i in range(rows):
                if not checkValid(curr, i, j):
                    return False
        # check squares
        for i in range(0, rows, 3):
            for j in range(0, cols, 3):
                curr = set()
                for di in range(3):
                    for dj in range(3):
                        if not checkValid(curr, i + di, j + dj):
                            return False
        return True

        
# @lc code=end

