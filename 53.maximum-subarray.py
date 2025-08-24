#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # dp[i] = max(nums[i] + dp[i - 1], nums[i])
        # maxSoFar[i] = max(maxSoFar[i], dp[i])
        dp = nums[0]
        maxSoFar = nums[0]
        for i in range(1, len(nums)):
            dp = max(dp + nums[i], nums[i])
            maxSoFar = max(dp, maxSoFar)
        return maxSoFar
        
# @lc code=end

