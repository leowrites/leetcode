#
# @lc app=leetcode id=22 lang=python3
#
# [22] Generate Parentheses
#

# @lc code=start
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def backtrack(left, right, currString):
            if left == right == n:
                res.append(currString)
            if left < n:
                backtrack(left + 1, right, currString + "(")
            if right < left:
                backtrack(left, right + 1, currString + ")")
            
        backtrack(0, 0, "")
        return res


        
# @lc code=end

