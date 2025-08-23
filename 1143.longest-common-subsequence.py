#
# @lc app=leetcode id=1143 lang=python3
#
# [1143] Longest Common Subsequence
#

# @lc code=start
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # dp[i][j] = max(dp[i - 1][j - 1] if text1[i] == text2[j] else dp[i - 1][j] or dp[i][j - 1])
        # Lesson:
        #   - Very important: identify what the two dimensions are
        #   - Consider what each state dp[i][j] means
        #   - Write recurrence relation
        # In this case:
        #   - dp[i][j] means up to text1[:i], text2[:j], what is the longest common subsequence?
        #       The decision to make is wether to use i, j, regardless of the future.
        #   - The LCS at i, j = 1 (if text1[i] == text2[j]) + the LCS between text1[:i - 1] and text2[:j - 1]
        #   - if i != j, then there are two possibilities: either we don't use i, or j, so we look at i - 1, j or i, j - 1
        t1 = len(text1)
        t2 = len(text2)
        dp = [[0] * t2 for _ in range(t1)]
        for i in range(t1):
            for j in range(t2):
                if i == j == 0:
                    dp[i][j] = 1 if text1[i] == text2[j] else 0
                elif i == 0:
                    dp[i][j] = max(1 if text1[i] == text2[j] else 0, dp[i][j - 1])
                elif j == 0:
                    dp[i][j] = max(1 if text1[i] == text2[j] else 0, dp[i - 1][j])
                elif text1[i] == text2[j]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[t1 - 1][t2 - 1]


        
# @lc code=end

