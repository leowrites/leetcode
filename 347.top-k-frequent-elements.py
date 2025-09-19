#
# @lc app=leetcode id=347 lang=python3
#
# [347] Top K Frequent Elements
#

# @lc code=start
import heapq
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # most frequent -> min heap where h[0] is the element to be swapped out
        h = []
        freq = Counter(nums)
        for key, val in freq.items():
            if len(h) < k:
                heapq.heappush(h, (val, key))
            else:
                heapq.heappushpop(h, (val, key))
        return [k for _, k in h]
        
        
# @lc code=end

