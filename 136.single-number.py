#
# @lc app=leetcode id=136 lang=python3
#
# [136] Single Number
#

# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # if 32 bits, it will include all n in nums. each value can be converted
        # to bit representation, so we xor. if a value appears twice, it will return to 0
        # if we have 2, 1, 3, 1, 3
        # 0010 -> 0010
        # 0001 -> 0011
        # 0011 -> 0000
        # 0001 -> 0001
        # 0011 -> 0010
        a = 0
        for n in nums:
            a = a ^ n
        return a

        
# @lc code=end

