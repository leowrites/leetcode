#
# @lc app=leetcode id=219 lang=python3
#
# [219] Contains Duplicate II
#

# @lc code=start
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        m = {}
        for i, n in enumerate(nums):
            if n in m and abs(i - m[n]) <= k:
               return True 
            m[n] = i
        return False

        
# @lc code=end

