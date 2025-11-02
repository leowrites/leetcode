#
# @lc app=leetcode id=1631 lang=python3
#
# [1631] Path With Minimum Effort
#

# @lc code=start

import heapq

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        pq = [(0, 0, 0)]
        rows = len(heights)
        cols = len(heights[0])
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        # minimum cost to cell so far, could be improved unless we have visited the cell

        # should track maximum effort along the entire route
        costToNode = [[float('inf')] * cols for _ in range(rows)]
        while len(pq) > 0:
            cost, i, j = heapq.heappop(pq)
            if cost > costToNode[i][j]:
                continue
            for di, dj in dirs:
                ni = i + di
                nj = j + dj
                if 0 <= ni < rows and 0 <= nj < cols and max(cost, abs(heights[ni][nj] - heights[i][j])) < costToNode[ni][nj]:
                   costToNode[ni][nj] = max(cost, abs(heights[ni][nj] - heights[i][j]))
                   pq.append((costToNode[ni][nj], ni, nj))
        return costToNode[-1][-1]
            
        
# @lc code=end

