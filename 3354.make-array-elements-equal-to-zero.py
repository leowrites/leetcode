#
# @lc app=leetcode id=3354 lang=python3
#
# [3354] Make Array Elements Equal to Zero
#

# @lc code=start
class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        selections = 0
        # using prefix/postfix sum
        # at each nums[i] == 0, if sum to left == sum to right, add 2 to selection
        prefix = [0] * (len(nums) + 1)

        # [1, 0, 2, 0, 3]
        # [0, 1, 1, 3, 3, 6]
        #   (1, 5) (3, 3) 

        prefix[1] = nums[0]
        for i in range(2, len(nums) + 1):
            prefix[i] = prefix[i - 1] + nums[i - 1]
        for i in range(len(nums)):
            if nums[i] == 0:
                if abs(prefix[i] - (prefix[-1] - prefix[i + 1])) == 0:
                    selections += 2
                if abs(prefix[i] - (prefix[-1] - prefix[i + 1])) == 1:
                    selections += 1
        return selections

        
# @lc code=end

