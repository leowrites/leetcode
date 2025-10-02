/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (!(0 <= row && row < grid.size() && 0 <= col && col < grid[0].size())) {
            return 0;
        }
        if (grid[row][col] == 0) {
            return 0;
        }
        grid[row][col] = 0;
        int curr = 1;
        curr += dfs(grid, row + 1, col);
        curr += dfs(grid, row - 1, col);
        curr += dfs(grid, row, col + 1);
        curr += dfs(grid, row, col - 1);
        return curr;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSoFar = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                maxSoFar = max(maxSoFar, dfs(grid, i, j));
            }
        }
        return maxSoFar;
    }
};
// @lc code=end

