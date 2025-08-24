#
# @lc app=leetcode id=210 lang=python3
#
# [210] Course Schedule II
#

# @lc code=start
from collections import defaultdict
class Solution:
   def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # topological sort, we can start anywhere but use a stack to maintain the reverse order
        # [1, 0] becomes 0 -> 1, which means after 0, we can do 1
        adjList = defaultdict(list)
        for pre, course in prerequisites:
            adjList[pre].append(course)
        
        stack = []
        visited = [False] * numCourses
        recStack = [False] * numCourses
        def dfs(i):
            if recStack[i]:
                return False
            if visited[i]:
                return True
            visited[i] = recStack[i] = True
            for n in adjList[i]:
                if not dfs(n):
                    return False
            recStack[i] = False
            stack.append(i)
            return True
            
        for i in range(numCourses):
            if not dfs(i):
                return []
        return stack
        
# @lc code=end

