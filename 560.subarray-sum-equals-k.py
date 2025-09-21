#
# @lc app=leetcode id=560 lang=python3
#
# [560] Subarray Sum Equals K
#

# @lc code=start
from collections import defaultdict
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix = 0
        prefix_dict = defaultdict(int)
        prefix_dict[0] = 1
        count = 0
        for n in nums:
            prefix += n
            # current prefix - some prev number = k
            if prefix - k in prefix_dict:
                count += prefix_dict[prefix - k]
            prefix_dict[prefix] += 1
        return count

        
# @lc code=end

