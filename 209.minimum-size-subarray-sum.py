#
# @lc app=leetcode id=209 lang=python3
#
# [209] Minimum Size Subarray Sum
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        curr = 0
        l = 0
        minSoFar = float('inf')
        for r in range(len(nums)):
            curr += nums[r]
            while curr >= target:
                minSoFar = min(minSoFar, r - l + 1)
                curr -= nums[l]
                l += 1
        return minSoFar if minSoFar != float('inf') else 0
        
# @lc code=end

