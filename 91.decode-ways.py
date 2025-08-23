#
# @lc app=leetcode id=91 lang=python3
#
# [91] Decode Ways
#

# @lc code=start
class Solution:
    def numDecodings(self, s: str) -> int:
        # start from back
        # if 0, then it is # of ways to combine dp[i - 1]
        # else, check i - 1
        #   if i - 1 is 1 or 2, then # of ways to decode dp[i - 2]
        #   if i - 1 is not 1 or 2, then # of ways to decide dp[i - 1]
        n = len(s)
        dp = [1] + [0] * n
        for i, c in enumerate(s):
            if c == '0' and (i == 0 or s[i - 1] != '1' and s[i - 1] != '2'):
                return 0
            canCombineWithPrev = i > 0 and 1 <= int(s[i - 1] + c) <= 26 and s[i - 1] != '0'
            if c == '0':
                dp[i + 1] = dp[i - 1]
            else:
                dp[i + 1] = dp[i]
                if canCombineWithPrev:
                    dp[i + 1] += dp[i - 1]
        return dp[n]
        
# @lc code=end

