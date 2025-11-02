#
# @lc app=leetcode id=2257 lang=python3
#
# [2257] Count Unguarded Cells in the Grid
#

# @lc code=start
class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        # we go left -> right, then right to left
        # If we see a G, set all cells after it to be -1, and stop at W
        # Do the same for columns
        # 2 * m * n
        # ungarded = 1
        # wall = 0
        # guard = -1
        matrix = [[1] * n for _ in range(m)]
        for i, j in guards:
            matrix[i][j] = -2
        for i, j in walls:
            matrix[i][j] = 0
 
        def helper(i, j, shouldSet):
            if matrix[i][j] == -2:
                return True
            elif matrix[i][j] == 0:
                return False
            if shouldSet:
                matrix[i][j] = -1
            return shouldSet
        for i in range(m):
            shouldSet = False
            for j in range(n):
                shouldSet = helper(i, j, shouldSet)
            for j in range(n - 1, -1, -1):
                shouldSet = helper(i, j, shouldSet)
        for j in range(n):
            shouldSet = False
            for i in range(m):
                shouldSet = helper(i, j, shouldSet)
            for i in range(m - 1, -1, -1):
                shouldSet = helper(i, j, shouldSet)
        result = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 1:
                    result += 1
        return result

        
# @lc code=end

