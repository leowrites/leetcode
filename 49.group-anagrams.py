#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#

# @lc code=start
from collections import Counter, defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        for s in strs:
            chars = Counter(s)
            key = ["0"] * 26
            for k, v in chars.items():
                key[ord(k) - 97] = str(v)
            groups[".".join(key)].append(s)
        return list(groups.values())
        
# @lc code=end

