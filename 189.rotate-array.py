#
# @lc app=leetcode id=189 lang=python3
#
# [189] Rotate Array
#

# @lc code=start
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # linear space..
        # only rotate if it's currently out of order?
        seen = [False] * len(nums)
        for s in range(len(nums)):
            if seen[s]: 
                continue
            prev_value = nums[s]
            curr_index = (s + k) % len(nums)
            while not seen[curr_index]:
                nums[curr_index], prev_value = prev_value, nums[curr_index]
                seen[curr_index] = True
                curr_index = (curr_index + k) % len(nums)

        
# @lc code=end

