#
# @lc app=leetcode id=232 lang=python3
#
# [232] Implement Queue using Stacks
#

# @lc code=start
class MyQueue:

    def __init__(self):
        self.stack = []

    def push(self, x: int) -> None:
        # we should keep -1 as head of queue so it's fast to peek and pop
        # this means the newest value should be at the 0th index
        placeHolder = [0] * (len(self.stack) + 1)
        placeHolder[0] = x
        for i in range(len(self.stack)):
            placeHolder[i + 1] = self.stack[i]
        self.stack = placeHolder

    def pop(self) -> int:
        return self.stack.pop()

    def peek(self) -> int:
        return self.stack[-1]
        
    def empty(self) -> bool:
        return len(self.stack) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
# @lc code=end

