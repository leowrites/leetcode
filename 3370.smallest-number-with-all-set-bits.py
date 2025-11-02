#
# @lc app=leetcode id=3370 lang=python3
#
# [3370] Smallest Number With All Set Bits
#

# @lc code=start
class Solution:
    def smallestNumber(self, n: int) -> int:
        res = 0
        while n > 0:
            # push 1 to res
            res = (res << 1) | 1
            n >>= 1
        return res
        
# @lc code=end

