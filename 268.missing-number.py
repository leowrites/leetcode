#
# @lc app=leetcode id=268 lang=python3
#
# [268] Missing Number
#

# @lc code=start
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # sum two times, one of nums, second of all nums between 0, n
        # then subtract to get the missing one
        # Note: can combine below into one loop
        res = sum(i for i in range(len(nums) + 1))
        total = sum(i for i in nums)
        return res - total

        
# @lc code=end

