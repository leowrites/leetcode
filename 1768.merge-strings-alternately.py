#
# @lc app=leetcode id=1768 lang=python3
#
# [1768] Merge Strings Alternately
#

# @lc code=start
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        r = ""
        for i in range(max(word1, word2)):
            if i < len(word1):
                r += word1[i]
            if i < len(word2):
                r += word2[i]
        return r
        
# @lc code=end

