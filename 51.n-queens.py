#
# @lc app=leetcode id=51 lang=python3
#
# [51] N-Queens
#

# @lc code=start
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        solutions = []
        def allowed(q1, q2):
            return abs(q1[0] - q2[0]) != abs(q1[1] - q2[1]) and q1[0] - q2[0] != 0 and q1[1] - q2[1] != 0
        
        prevQueens = []
        currPath = []
        board = [["." for _ in range(n)] for _ in range(n)]
        def dfs():
            if len(currPath) == n:
                solutions.append(currPath.copy())
                return
            
            # for i in n, try to place the queen on [level][i]
            for i in range(n):
                row = "." * i + "Q" + "." * (n - i - 1)
                # if the len(currPath), i will not overlap with previous queens, continue
                if all(allowed(q, [len(currPath), i]) for q in prevQueens):
                    prevQueens.append([len(currPath), i])
                    currPath.append(row)
                    dfs()
                    prevQueens.pop()
                    currPath.pop()
        dfs()
        return solutions

        
# @lc code=end

