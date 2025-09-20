#
# @lc app=leetcode id=304 lang=python3
#
# [304] Range Sum Query 2D - Immutable
#

# @lc code=start
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        # likely prefix sum/dp
        # each cell can easily calculate the sum to cell from 0, 0
        # so to sum a region, we can do some math:
        # prefix[row2][col2] - prefix[row2][col2 - 1] - prefix[row1 - 1][col2] + prefix[row1 - 1][col1 - 1]
        # to construct the prefix, we can do prefix[row][col] = 
        # matrix[row][col] + prefix[row - 1][col] + prefix[row][col - 1] - prefix[row - 1][col - 1]
        self.rows, self.cols = len(matrix) + 1, len(matrix[0]) + 1
        self.prefix = [[0] * self.cols for _ in range(self.rows)]
        for i in range(1, self.rows):
            for j in range(1, self.cols):
                # if out of bound, should just be 0. Handle this later or maybe we have place holder 0s
                self.prefix[i][j] = matrix[i - 1][j - 1] + self.prefix[i - 1][j] + self.prefix[i][j - 1] - self.prefix[i - 1][j - 1]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        row1, row2, col1, col2 = row1 + 1, row2 + 1, col1 + 1, col2 + 1
        return (
            self.prefix[row2][col2] -
            self.prefix[row2][col1 - 1] -
            self.prefix[row1 - 1][col2] +
            self.prefix[row1 - 1][col1 - 1]
        )



# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
# @lc code=end

