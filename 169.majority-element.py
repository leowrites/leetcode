#
# @lc app=leetcode id=169 lang=python3
#
# [169] Majority Element
#

# @lc code=start
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # the idea is we can subtract the frequency of all other elements
        # by the majority element, and the majority element will still be more
        curr = None
        count = 0
        # if count == 0, we update curr element
        for n in nums:
            if n != curr:
                count -= 1
            else:
                count += 1
            if count <= 0:
                curr = n
                count = 1
        return curr
        
# @lc code=end

