#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        right = [']', '}', ')']
        for c in s:
            if c in right and len(stack) == 0:
                return False
            elif c == ']' and stack[-1] == '[':
                stack.pop()
            elif c == '}' and stack[-1] == '{':
                stack.pop()
            elif c == ')' and stack[-1] == '(':
                stack.pop()
            elif c in right:
                return False
            else:
                stack.append(c)
        return len(stack) == 0
            
        
# @lc code=end

