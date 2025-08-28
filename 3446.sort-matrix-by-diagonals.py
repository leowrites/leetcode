#
# @lc app=leetcode id=3446 lang=python3
#
# [3446] Sort Matrix by Diagonals
#

# @lc code=start
class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        def processTriangle(start, end, step, reverse):
            for i in range(start, end, step):
                row = i if reverse else 0
                col = i if not reverse else 0
                curr = []
                while row < n and col < n:
                    curr.append(grid[row][col])
                    row += 1
                    col += 1
                curr.sort()
                if reverse: curr.reverse()
                row = i if reverse else 0
                col = i if not reverse else 0
                index = 0
                while row < n and col < n:
                    grid[row][col] = curr[index]
                    index += 1
                    row += 1
                    col += 1
        processTriangle(n - 1, -1, -1, True)
        processTriangle(1, n, 1, False)
        return grid
            
        
# @lc code=end

