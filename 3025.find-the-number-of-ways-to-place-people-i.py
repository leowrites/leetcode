#
# @lc app=leetcode id=3025 lang=python3
#
# [3025] Find the Number of Ways to Place People I
#

# @lc code=start
class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        # sort x by increasing, then y by increasing as well. 
        # This ensures all points after i is to the right of i, and they can be above or below i.
        # If the point is above current y, we should continue. There should only be 1 valid point 
        # for each B.x. For that B, we should record the y, so subsequent B needs to be above that y,
        # otherwise it will overlap with the previous point
        # Iterate over each point. For each index i, iterate over the points at i + 1. 
        points.sort(key = lambda p: (p[0], -p[1]))
        count = 0
        for i in range(len(points)):
            a = points[i]
            minY = float('-inf')
            for j in range(i + 1, len(points)):
                b = points[j]
                if b[1] > a[1] or b[1] <= minY:
                    continue
                minY = b[1]
                count += 1
        return count

        
# @lc code=end

