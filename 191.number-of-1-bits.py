#
# @lc app=leetcode id=191 lang=python3
#
# [191] Number of 1 Bits
#

# @lc code=start
class Solution:
    def hammingweight(self, n: int) -> int:
        # convert to a string and count doesn't feel efficient
        # right shift?
        count = 0
        while n > 0:
            count += n & 1
            n >>= 1
        return count
        
# @lc code=end

