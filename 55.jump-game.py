#
# @lc app=leetcode id=55 lang=python3
#
# [55] Jump Game
#

# @lc code=start
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # Key: track all reachable positions simultaneously. Instead of "taking the jump", we track
        # if an index can be reached, and if so what is the maximum we can jump starting at that index
        farthest = 0
        for i in range(len(nums)):
            farthest = max(farthest, nums[i] + i)
            if nums[i] == 0 and farthest == i and farthest < len(nums):
               return False
        return farthest >= len(nums) - 1

        
# @lc code=end

