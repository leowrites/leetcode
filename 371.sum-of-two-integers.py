#
# @lc app=leetcode id=371 lang=python3
#
# [371] Sum of Two Integers
#

# @lc code=start
class Solution:
    def getSum(self, a: int, b: int) -> int:
        c = 0
        i = 0
        res = 0
        for i in range(32):
            v = (a & 1) ^ (b & 1) ^ (c & 1)
            c = (a & 1) & (b & 1) | (b & 1) & (c & 1) | (a & 1) & (c & 1)
            res |= v << i
            i += 1
            a >>= 1
            b >>= 1
        # If res > ..., the sign bit is sign, and the intended value is negative
        # in two's complement. Achieve this by flipping the lower 32 bits and 
        # ~ which is equal to subtracting 2 ** 32
        if res > 0x7FFFFFFF:
            res = ~(res ^ 0xFFFFFFFF)
        return res
        
        
# @lc code=end

