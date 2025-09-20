#
# @lc app=leetcode id=238 lang=python3
#
# [238] Product of Array Except Self
#

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # invariant: prefix[i] = prod(prefix[:i]). postfix[i] = prod(postfix[i + 1:])
        # prefix[0] = 1, since prefix[1] = prefix[0] * nums[0].
        res = [1] * len(nums)
        for i in range(1, len(nums)):
            res[i] = nums[i - 1] * res[i - 1]

        postfix = 1
        for i in range(len(nums) - 2, -1, -1):
            postfix = postfix * nums[i + 1]
            res[i] = res[i] * postfix
        return res
        
# @lc code=end

