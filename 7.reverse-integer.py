#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        int_max = 2**31 - 1
        int_min = -(2**31)
        strList = list(str(x))
        strList.reverse()
        if strList[-1] == "-":
            res = int("-" + "".join(strList[:-1]))
            return 0 if res < int_min else res
        res = int("".join(strList))
        return 0 if res > int_max else res
            
       
        
# @lc code=end

