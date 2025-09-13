#
# @lc app=leetcode id=2785 lang=python3
#
# [2785] Sort Vowels in a String
#

# @lc code=start
class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = ['a', 'e','i', 'o', 'u', 'A', 'E','I', 'O', 'U']
        collectedVowels = []
        for c in s:
            if c in vowels:
                collectedVowels.append(c)
        collectedVowels.sort()
        i = 0
        res = ""
        for c in s:
            if c not in vowels:
                res += c
            elif i < len(collectedVowels):
                res += collectedVowels[i]
                i += 1
        return res
        
# @lc code=end

