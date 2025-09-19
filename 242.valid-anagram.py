#
# @lc app=leetcode id=242 lang=python3
#
# [242] Valid Anagram
#

# @lc code=start
from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        c1 = Counter(s)
        c2 = Counter(t)
        return all(c2[k] == v for k, v in c1.items()) and all(c1[k] == v for k, v in c2.items())
        
# @lc code=end

