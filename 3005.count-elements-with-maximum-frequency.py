#
# @lc app=leetcode id=3005 lang=python3
#
# [3005] Count Elements With Maximum Frequency
#

# @lc code=start
from collections import Counter
class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        counter = Counter(nums)
        freq = 0
        maxSoFar = 0
        for _, v in counter.items():
            if v > maxSoFar:
                maxSoFar = v
                freq = v
            elif v == maxSoFar:
                freq += v
        return freq

        
# @lc code=end

