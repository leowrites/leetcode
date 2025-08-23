#
# @lc app=leetcode id=97 lang=python3
#
# [97] Interleaving String
#

# @lc code=start
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        dp = [[False] * (len(s2) + 1) for _ in range(len(s1) + 1)]
        # Initialize the base case. Since i, j is exclusive, it means to use an empty string
        dp[0][0] = True

        for j in range(1, len(s2) + 1):
            # Note j is exclusive here, so to index s2 we need to -1
            dp[0][j] = dp[0][j - 1] and s2[j - 1] == s3[j - 1]
        for i in range(1, len(s1) + 1):
            dp[i][0] = dp[i - 1][0] and s1[i - 1] == s3[i - 1]

        for p1 in range(1, len(s1) + 1):
            for p2 in range(1, len(s2) + 1):
                s3Index = p1 + p2 - 1
                dp[p1][p2] = (s1[p1 - 1] == s3[s3Index] and dp[p1 - 1][p2]) or (s2[p2 - 1] == s3[s3Index] and dp[p1][p2 - 1])
        return dp[len(s1)][len(s2)]

        
# @lc code=end

