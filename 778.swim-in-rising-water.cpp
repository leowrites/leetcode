/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // bfs with timestamp.
        // we can use a heap to check which squares can be explored
        int rows = grid.size(), cols = grid[0].size();
        int time = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        using T = tuple<int, int, int>;
        std::priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        while (!pq.empty()) {
            // if the time of the root of the queue > time, increase time 
            auto [t, i, j] = pq.top();
            if (t > time) {
                time = t;
            }
            if (i == rows - 1 && j == cols - 1) {
                return time;
            }
            pq.pop();
            for (const auto& [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (0 <= ni && ni < rows && 0 <= nj && nj < cols && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    pq.push({grid[ni][nj], ni, nj});
                }
            }
        }
        return time;
    }
};
// @lc code=end

