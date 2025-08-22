#
# @lc app=leetcode id=139 lang=python3
#
# [139] Word Break
#

# @lc code=start
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # if we start top down:
        #   starting at the back, for each w in wordDict, if wordDict[n - len(w): n] == w, and
        #   all of wordBreak(s[:n - len(w)]), then it is possible. Otherwise, it is not possible
        # bottom up:
        # n = len(s)
        # for i in range(n):
        #     for w in wordDict:
        #         if i > len(w) and dp[i - len(w)]:
        #             dp[i] = True
        # return dp[n - 1]

        # Learning: don't be afraid to loop through all words at each index even though it feels like
        # bruteforce
        n = len(s)
        dp = [True] + [False] * n
        for i in range(n + 1):
            for w in wordDict:
                if i >= len(w) and s[i - len(w): i] == w and dp[i - len(w)]:
                    dp[i] = True
        return dp[n]
        
        
# @lc code=end

