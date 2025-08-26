#
# @lc app=leetcode id=115 lang=python3
#
# [115] Distinct Subsequences
#

# @lc code=start
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        sLen = len(s)
        tLen = len(t)
        dp = [[0] * (tLen) for _ in range(sLen)]
        dp[0][0] = 1 if s[0] == t[0] else 0
        for i in range(1, sLen):
            dp[i][0] = dp[i - 1][0] + (1 if s[i] == t[0] else 0)
        for i in range(1, sLen):
            for j in range(1, tLen):
                dp[i][j] = dp[i - 1][j]
                if s[i] == t[j]:
                    dp[i][j] += dp[i - 1][j - 1]
        return dp[sLen - 1][tLen - 1]
        
        
# @lc code=end

