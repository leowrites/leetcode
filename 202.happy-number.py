#
# @lc app=leetcode id=202 lang=python3
#
# [202] Happy Number
#

# @lc code=start
class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        currSum = sum(int(i) ** 2 for i in str(n))
        while not currSum in seen and currSum != 1:
            seen.add(currSum)
            currSum = sum(int(i) ** 2 for i in str(currSum))
        return currSum == 1
        
        
# @lc code=end

