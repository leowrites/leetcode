#
# @lc app=leetcode id=11 lang=python3
#
# [11] Container With Most Water
#

# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        # Two pointers:
        # 1. if height[l] < height[r], inc l
        # 2. else, dec r
        # stop when l >= r 
        l, r = 0, len(height) - 1
        maxArea = 0
        while l < r:
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return maxArea
        
# @lc code=end

