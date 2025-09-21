#
# @lc app=leetcode id=567 lang=python3
#
# [567] Permutation in String
#

# @lc code=start
from collections import Counter, defaultdict
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        freq = Counter(s1)
        window = defaultdict(int)
        for i in range(len(s1)):
            window[s2[i]] += 1
        if all(window[k] == v for k, v in freq.items()):
            return True

        for i in range(len(s2) - len(s1)):
            window[s2[i]] -= 1
            window[s2[i + len(s1)]] += 1
            if all(window[k] == v for k, v in freq.items()):
                return True
        return False
        
# @lc code=end

