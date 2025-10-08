/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
#include <queue>
#include <utility>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> pacificQ;
        queue<pair<int, int>> atlanticQ;
        std::set<pair<int, int>> reachable;
        vector<vector<int>> res;
        // enqueue cells bordering pacific
        for (int i = 0; i < rows; i++) {
            pacificQ.push({i, 0});
            atlanticQ.push({i, cols - 1});
        }
        for (int i = 0; i < cols; i++) {
            pacificQ.push({0, i});
            atlanticQ.push({rows - 1, i});
        }
        vector<vector<int>> visited(rows, vector<int>(cols, false));
        while (!pacificQ.empty()) {
            const auto [i, j] = pacificQ.front();
            pacificQ.pop();
            if (visited[i][j]) {
                continue;
            }
            reachable.insert({i, j});
            visited[i][j] = true;
            for (const auto & [di, dj]: dirs) {
                int ni = i + di, nj = j + dj;
                if (0 <= ni && ni < rows && 0 <= nj && nj < cols && heights[i][j] <= heights[ni][nj] && !visited[i][j]) {
                    pacificQ.push({ni, nj});
                }
            }
        }
        // rerun for atlantic. If i, j in reachable, add it to result
        vector<vector<int>> atlanticVisited(rows, vector<int>(cols, false));
        while (!atlanticQ.empty()) {
            const auto [i, j] = atlanticQ.front();
            atlanticQ.pop();
            if (atlanticVisited[i][j]) {
                continue;
            }
            if (reachable.find({i, j}) != reachable.end()) {
                res.push_back({i, j});
            }
            atlanticVisited[i][j] = true;
            for (const auto & [di, dj]: dirs) {
                int ni = i + di, nj = j + dj;
                if (0 <= ni && ni < rows && 0 <= nj && nj < cols && heights[i][j] <= heights[ni][nj] && !atlanticVisited[i][j]) {
                    atlanticQ.push({ni, nj});
                }
            }
        }
        return res;
    }
};
// @lc code=end

