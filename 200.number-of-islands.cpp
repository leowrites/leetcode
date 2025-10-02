/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <utility>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        auto bfs = [&](int row, int col) {
            q.push({row, col});
            grid[row][col] = '0';
            while (q.size()) {
                auto [i, j] = q.front();
                q.pop();
                for (const auto &[i_dir, j_dir]: dirs) {
                    int ni = i + i_dir, nj = j + j_dir;
                    if (0 <= ni && ni < rows && 0 <= nj && nj < cols && grid[ni][nj] == '1') {
                        grid[ni][nj] = '0';
                        q.push({ni, nj});
                    }
                }
            }
        };

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1') {
                    islands++;
                    bfs(row, col);
                }
            }
        }
        return islands;
    }
};
// @lc code=end

