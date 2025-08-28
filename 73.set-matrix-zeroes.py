#
# @lc app=leetcode id=73 lang=python3
#
# [73] Set Matrix Zeroes
#

# @lc code=start
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows, cols = len(matrix), len(matrix[0])
        zeroinFirstCol = False;
        for i in range(rows):
            if matrix[row][0] == 0: zeroinFirstCol = True;
            for j in range(cols):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for row in range(len(matrix) - 1, -1, -1):
            for col in range(len(matrix[0]) - 1, 0, -1):
                if matrix[row][0] == 0 or matrix[0][col] == 0:
                    matrix[row][col] = 0
            if zeroinFirstCol:
                matrix[row][0] = 0
                
        
# @lc code=end

