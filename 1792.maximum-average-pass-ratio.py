#
# @lc app=leetcode id=1792 lang=python3
#
# [1792] Maximum Average Pass Ratio
#

# @lc code=start
import heapq
class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        maxHeap = []
        # each element should be [increase, index]
        for i in range(len(classes)):
            p, t = classes[i]
            improvement = (p + 1) / (t + 1) - (p / t) 
            heapq.heappush(maxHeap, [-improvement, i])
        for i in range(extraStudents):
            _, classIndex = heapq.heappop(maxHeap)
            classes[classIndex][0] += 1
            classes[classIndex][1] += 1
            p = classes[classIndex][0]
            t = classes[classIndex][1]
            improvement = (p + 1) / (t + 1) - (p / t) 
            heapq.heappush(maxHeap, [-improvement, classIndex])
        return sum(p / t for p, t in classes) / len(classes)
            
        
# @lc code=end

