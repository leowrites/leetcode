#
# @lc app=leetcode id=329 lang=python3
#
# [329] Longest Increasing Path in a Matrix
#

# @lc code=start
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        dp = [[float('-inf')] * cols for _ in range(rows)]
        maxLen = 1
        def dfs(i, j):
            nonlocal maxLen
            if dp[i][j] != float('-inf'):
                return dp[i][j]
            maxSoFar = 0
            for newI, newJ in [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]]:
                if 0 <= newI < rows and 0 <= newJ < cols and matrix[i][j] < matrix[newI][newJ]:
                    maxSoFar = max(maxSoFar, dfs(newI, newJ))
            dp[i][j] = 1 + maxSoFar
            maxLen = max(maxLen, dp[i][j])
            return dp[i][j]

        for i in range(rows):
            for j in range(cols):
                if dp[i][j] == float('-inf'):
                    dfs(i, j)
        return maxLen
                    
        
# @lc code=end

