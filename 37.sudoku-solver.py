#
# @lc app=leetcode id=37 lang=python3
#
# [37] Sudoku Solver
#

# @lc code=start
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = cols = 9
        rowVals = [set() for _ in range(rows)]
        colVals = [set() for _ in range(cols)]
        subgrids = [set() for _ in range(cols)]
        empty = []

        def backtrack(i):
            if i == len(empty):
                return True
            r, c = empty[i]
            grid = (r // 3) * 3 + c // 3
            for n in range(1, 10):
                n = str(n)
                if n not in rowVals[r] and n not in colVals[c] and n not in subgrids[grid]:
                    rowVals[r].add(n)
                    colVals[c].add(n)
                    subgrids[grid].add(n)
                    board[r][c] = n
                    if backtrack(i + 1):
                        return True
                    rowVals[r].remove(n)
                    colVals[c].remove(n)
                    subgrids[grid].remove(n)
                    board[r][c] = '.'
            return False

        for i in range(rows):
            for j in range(cols):
                if board[i][j] != '.':
                    rowVals[i].add(board[i][j])
                    colVals[j].add(board[i][j])
                    subgrids[(i // 3) * 3 + j // 3].add(board[i][j])
                else:
                    empty.append([i, j])
        backtrack(0)

            

        
# @lc code=end

