#
# @lc app=leetcode id=735 lang=python3
#
# [735] Asteroid Collision
#

# @lc code=start
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for a in asteroids:
            if a > 0:
                stack.append(a)
                continue
            while stack and stack[-1] > 0 and abs(stack[-1]) < abs(a):
                stack.pop()
            if not stack or stack[-1] < 0:
                stack.append(a)
            elif abs(stack[-1]) == abs(a):
                stack.pop()
        return stack

        
# @lc code=end

