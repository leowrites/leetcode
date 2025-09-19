#
# @lc app=leetcode id=14 lang=python3
#
# [14] Longest Common Prefix
#

# @lc code=start
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        i = 0
        curr = ""
        for i in range(200):
            if i >= len(strs[0]):
                return curr
            c = strs[0][i]
            if not all(i < len(s) and s[i] == c for s in strs):
                return curr
            curr += c
        return curr
                
            
            
        
# @lc code=end

