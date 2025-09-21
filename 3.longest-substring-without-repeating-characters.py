#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        longest = 0
        window = set()
        for r in range(len(s)):
            window.add(s[r])
            while s[r] in window:
                longest = max(longest, len(window))
                window.remove(s[l])
                l += 1
        return longest
        
# @lc code=end

