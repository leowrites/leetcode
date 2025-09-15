#
# @lc app=leetcode id=1935 lang=python3
#
# [1935] Maximum Number of Words You Can Type
#

# @lc code=start
class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split()
        count = 0
        for w in words:
            if any(c in brokenLetters for c in w):
                continue
            count += 1
        return count
        
# @lc code=end

