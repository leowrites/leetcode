#
# @lc app=leetcode id=2013 lang=python3
#
# [2013] Detect Squares
#

# @lc code=start
from collections import defaultdict

class DetectSquares:

    def __init__(self):
        self.points = {}

    def add(self, point: List[int]) -> None:
        if (point[0], point[1]) not in self.points:
            self.points[(point[0], point[1])] = 0
        self.points[(point[0], point[1])] += 1

    def count(self, point: List[int]) -> int:
        count = 0

        for x, y in self.points.keys():
            if abs(point[0] - x) != abs(point[1] - y) or point[0] == x:
                continue
            if (point[0], y) not in self.points or (x, point[1]) not in self.points:
                continue
            count += self.points[(x, point[1])] * self.points[(point[0], y)] * self.points[(x, y)]

        return count
        


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)
# @lc code=end

