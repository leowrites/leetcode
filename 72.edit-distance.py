#
# @lc app=leetcode id=72 lang=python3
#
# [72] Edit Distance
#

# @lc code=start
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # Key:
        #   1. Always initialize with # of elements + 1 to indicates dp[i][j] means USING first i, j
        #       elements of word1 and word2. When using them to index word1 and word2, -1 from i/j
        #   2. Think carefully about base case

        dp = [[0] * (len(word1) + 1) for _ in range(len(word2) + 1)]
        # initialize the base cases
        for i in range(1, len(word1) + 1):
            dp[0][i] = i

        for i in range(1, len(word2) + 1):
            dp[i][0] = i

        for i in range(1, len(word2) + 1):
            for j in range(1, len(word1) + 1):
                if word1[j - 1] == word2[i - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1])
        return dp[len(word2)][len(word1)]
# @lc code=end

