#
# @lc app=leetcode id=3516 lang=python3
#
# [3516] Find Closest Person
#

# @lc code=start
class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        xToZ = abs(x - z)
        yToZ = abs(y - z)
        # whoever is closer should be returned. If they are the same distance apart 0 should be returned
        if xToZ < yToZ:
            return 1
        elif yToZ < xToZ:
            return 2
        else:
            return 0
        
# @lc code=end

