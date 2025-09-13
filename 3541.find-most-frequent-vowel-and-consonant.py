#
# @lc app=leetcode id=3541 lang=python3
#
# [3541] Find Most Frequent Vowel and Consonant
#

# @lc code=start
from collections import Counter

class Solution:
    def maxFreqSum(self, s: str) -> int:
        counter = Counter(s)
        maxVowel = max((v for k, v in counter.items() if k in ['a', 'e', 'i', 'o', 'u']), default=0)
        maxConsonant = max((v for k, v in counter.items() if k not in ['a', 'e', 'i', 'o', 'u']), default=0)
        return maxVowel + maxConsonant
        
# @lc code=end

