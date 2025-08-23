#
# @lc app=leetcode id=494 lang=python3
#
# [494] Target Sum
#

# @lc code=start
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        # to memo, the values can go into the negatives, so we can start at 2 * target
        dp = {}
        def rec(remain, index):
            if index < 0:
                return 1 if remain == 0 else 0
            if (index, remain) in dp:
                return dp[(index, remain)]
            # if only remain is 0, we should continue
            dp[(index, remain)] = rec(remain - nums[index], index - 1) + rec(remain + nums[index], index - 1)
            return dp[(index, remain)]
        return rec(target, n - 1)
        
# @lc code=end

