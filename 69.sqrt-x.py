#
# @lc app=leetcode id=69 lang=python3
#
# [69] Sqrt(x)
#

# @lc code=start
class Solution:
    def mySqrt(self, x: int) -> int:
        l, u = 0, x
        while l <= u:
            m = (u + l) // 2
            if m * m == x:
                return m
            if m * m < x and (m + 1) * (m + 1) > x:
                return m
            elif m * m > x:
                u = m
            else:
                l = m + 1

        
# @lc code=end

