#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
from collections import defaultdict
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = defaultdict(list)
        for i, n in enumerate(nums):
            d[n].append(i)
        for k, v in d.items():
            r = target - k
            if r in d:
                if r == k and len(v) == 2:
                    return [v[0], v[1]]
                if r != k:
                    return [v[0], d[r][0]]

        
# @lc code=end

