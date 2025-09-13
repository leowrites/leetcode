#
# @lc app=leetcode id=3227 lang=python3
#
# [3227] Vowels Game in a String
#

# @lc code=start
class Solution:
    def doesAliceWin(self, s: str) -> bool:
        # if odd, alice always wins
        # if even, alice also wins
        # she only loses if there is noting to remove
        vowels = sum(1 for c in s if c in ['a', 'e', 'i', 'o', 'u'])
        return False if vowels == 0 else True
        
# @lc code=end

