#
# @lc app=leetcode id=1025 lang=python3
#
# [1025] Divisor Game
#

# @lc code=start
class Solution:
    def divisorGame(self, n: int) -> bool:
        dp = [False] * (n + 1)
        if n == 1 or n == 3: return False
        if n == 2: return True
        dp[0] = True
        dp[1] = False
        dp[2] = True
        dp[3] = False
        for i in range(4, n + 1):
            dp[i] = any(dp[j] for j in range(1, ceil(sqrt(i)) + 1) if j < i and i % j == 0)
        return dp[n]

        
# @lc code=end

