#
# @lc app=leetcode id=75 lang=python3
#
# [75] Sort Colors
#

# @lc code=start
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        s = m = 0
        e = len(nums) - 1
        while m <= e:
            if nums[m] == 0:
                nums[s], nums[m] = nums[m], nums[s]
                s += 1
                m += 1
            elif nums[m] == 1:
                m += 1
            else:
                nums[e], nums[m] = nums[m], nums[e]
                e -= 1
        
# @lc code=end

