#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#

# @lc code=start
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operators = ['+', '-', '*', '/']
        for t in tokens:
            if t in operators:
                op2, op1 = stack.pop(), stack.pop()
                stack.append(int(eval(str(op1) + t + str(op2))))
            else:
                stack.append(int(t))
        return stack[0]
       
# @lc code=end

