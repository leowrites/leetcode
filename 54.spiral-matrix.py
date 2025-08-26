#
# @lc app=leetcode id=54 lang=python3
#
# [54] Spiral Matrix
#

# @lc code=start
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        count = 0
        rows, cols = len(matrix), len(matrix[0])
        x, y, dx, dy = 0, 0, 1, 0
        res = []
        while count < rows * cols:
            res.append(matrix[y][x])
            count += 1
            if not 0 <= x + dx < cols or not 0 <= y + dy < rows or matrix[y+dy][x+dx] == '.':
                dx, dy = -dy, dx
            matrix[y][x] = '.'
            x = x + dx
            y = y + dy
            
        return res
            
        
# @lc code=end

