#
# @lc app=leetcode id=498 lang=python3
#
# [498] Diagonal Traverse
#

# @lc code=start
class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        # multiplier 1 or -1. 1 = go to i + 1, j + 1. -1 = go to i - 1, j - 1.
        # if reached edge, flip to multiplier
        #   special case: in the corner, (top right or bottom left) , then we either move down or move to the right
        #   if not special case, only one of top, bot, left, right is hit. 
        #       If left or right is hit, add 1 to i
        #       If top or bot i shit, add 1 to j
        i = j = 0
        dir = -1
        rows, cols = len(mat), len(mat[0])
        res = []
        visited = 0
        while visited < rows * cols:
            visited += 1
            res.append(mat[i][j])
            newI, newJ = i + dir, j - dir
            if newI < 0 and newJ >= cols:
                newI = 1
                newJ = j
                dir = 1
            elif newI >= rows and newJ < 0:
                newJ = 1
                newI = i
                dir = -1
            elif newI < 0:
                newI = 0
                dir = 1
            elif newJ < 0:
                newJ = 0
                dir = -1
            elif newI >= rows:
                newI = rows - 1
                newJ = j + 1
                dir = -1
            elif newJ >= cols:
                newJ = cols - 1
                newI = i + 1
                dir = 1
            i, j = newI, newJ
        return res
            
        
# @lc code=end

