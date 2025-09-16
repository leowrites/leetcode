#
# @lc app=leetcode id=128 lang=python3
#
# [128] Longest Consecutive Sequence
#

# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # use a set 
        # go through each element in the set. if the previous element
        # is in the set, continue to the next element. While the next value
        # is in the set, increment counter and keep searching until it's not
        max_count = 0
        nums_set = set(nums)
        for v in nums_set:
            curr_count = 0
            if v - 1 in nums_set:
                continue
            c = v
            while c in nums_set:
                curr_count += 1
                c = c + 1
            max_count = max(max_count, curr_count)
        return max_count
        
        
# @lc code=end

