#
# @lc app=leetcode id=2125 lang=python3
#
# [2125] Number of Laser Beams in a Bank
#

# @lc code=start
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        total = 0
        prev = 0
        for row in bank:
            if "1" in row:
                c = row.count("1")
                total += c * prev
                prev = c
        return total

        
# @lc code=end

