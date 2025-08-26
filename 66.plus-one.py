#
# @lc app=leetcode id=66 lang=python3
#
# [66] Plus One
#

# @lc code=start
class Solution:
    def plusOne(self, digits: list[int]) -> List[int]:
        digits[len(digits) - 1] += 1
        for i in range(len(digits) - 1, 0, -1):
            if digits[i] > 9:
                digits[i] = 0
                digits[i - 1] += 1
        if digits[0] == 10:
            digits[0] = 0
            digits.insert(0, 1)
        return digits
        
# @lc code=end

