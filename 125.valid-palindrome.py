#
# @lc app=leetcode id=125 lang=python3
#
# [125] Valid Palindrome
#

# @lc code=start
class Solution:
    def isPalindrome(self, s: str) -> bool:
        parsed = ""
        for c in s:
            if c.isalnum():
                parsed += c.lower()
        l, r = 0, len(parsed) - 1
        while l < r:
            if parsed[l] != parsed[r]:
                return False
            l += 1
            r -= 1
        return True

        
# @lc code=end

