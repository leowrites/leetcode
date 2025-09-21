#
# @lc app=leetcode id=680 lang=python3
#
# [680] Valid Palindrome II
#

# @lc code=start
class Solution:
    def isPalindrome(self, s, l, r):
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

    def validPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        # do same as palindrome, when it does not match, check the two options by either including 
        # left or right
        while l < r:
            if s[l] == s[r]:
                l += 1
                r -= 1
            else:
                # since it does not match, check if any of the two options give a valid palindrome
                return self.isPalindrome(s, l + 1, r) or self.isPalindrome(s, l, r - 1)
        return True

        
# @lc code=end

