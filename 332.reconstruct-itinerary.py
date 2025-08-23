#
# @lc app=leetcode id=332 lang=python3
#
# [332] Reconstruct Itinerary
#

# @lc code=start
from collections import defaultdict
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adjList = defaultdict(list)
        tickets.sort()
        tickets.reverse()
        for f, t in tickets:
            adjList[f].append(t)
        res = []
        def dfs(src):
            while adjList[src]:
                dst = adjList[src].pop()
                dfs(dst)
            res.append(src)

        dfs('JFK')
        return res[::-1] 
        
# @lc code=end

