#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
#

# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # two issues we had before:
        #   1. we can start anywhere in the list
        #   2. sign flipping
        # How to track largest:
        #   1. curr is positive, so curr * max will be larger
        #   2. curr is negative, so curr * min will be larger
        #   3. neither are larger (if they were 0), then we should start again from the current
        #       number
        # How this solves the "start anywhere issue": we really only want to "start over" when
        #   we encountered a 0 because in any other case, negative and positive can both potentially
        #   contribute to a larger number
        # "We track the maximum and minimum product ending at each position. At
        # each step, the new max/min could be: the current number alone
        # (starting fresh), current number × previous max, or current number ×
        # previous min. We need both max and min because multiplying by a
        # negative number flips which one is larger."
        dp = largest = smallest = nums[0]
        n = len(nums)
        for i in range(1, n):
            largest, smallest = max(largest * nums[i], smallest * nums[i], nums[i]), min(largest * nums[i], smallest * nums[i], nums[i])
            dp = max(dp, largest)
        return dp
        
# @lc code=end

