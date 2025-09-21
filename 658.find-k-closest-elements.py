
# @lc app=leetcode id=658 lang=python3
#
# [658] Find K Closest Elements
#

# @lc code=start
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        s, e = 0, len(arr) - 1
        while e - s > k - 1:
            if abs(arr[s] - x) > abs(arr[e] - x):
                s += 1
            else:
                e -= 1
        return arr[s:e + 1]
        
# @lc code=end

