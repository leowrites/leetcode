#
# @lc app=leetcode id=190 lang=python3
#
# [190] Reverse Bits
#

# @lc code=start
class Solution:
    def reverseBits(self, n: int) -> int:
        # get least significant bit of n
        # do bit-wise or with res for the last bit
        # left shift res
        # right shift n
        res = 0
        i = 31
        while i > 0:
            res = res | (n & 1)
            res <<= 1
            n >>= 1
            i -= 1
        return res

        
# @lc code=end

