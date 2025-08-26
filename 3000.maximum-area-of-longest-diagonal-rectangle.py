#
# @lc app=leetcode id=3000 lang=python3
#
# [3000] Maximum Area of Longest Diagonal Rectangle
#

# @lc code=start
import math
class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        maxDiagonal = 0
        maxArea = 0
        for w, h in dimensions:
            diagonal = math.sqrt(w * w + h * h)
            area = w * h
            if diagonal > maxDiagonal:
                maxDiagonal = diagonal
                maxArea = area
            elif diagonal == maxDiagonal:
                maxArea = max(maxArea, area)
        return maxArea
        
# @lc code=end

