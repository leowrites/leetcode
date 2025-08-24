#
# @lc app=leetcode id=1493 lang=python3
#
# [1493] Longest Subarray of 1's After Deleting One Element
#

# @lc code=start
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        # if i == 1: zero[i] = zero[i - 1]. dp[i] = 1 + dp[i - 1]
        # if i == 0: zero[i] = i, dp[i] = i - zero[i - 1]
        n = len(nums)
        lastZero = 0 if nums[0] == 0 else -1
        dp = nums[0]
        maxSoFar = 0
        for i in range(1, n):
            if nums[i] == 1:
                dp = 1 + dp
            else:
                dp, lastZero = i - lastZero - 1, i
            maxSoFar = max(maxSoFar, dp + min(lastZero, 0))
        return maxSoFar
        
# @lc code=end

