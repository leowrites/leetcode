/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // start with the border, if there is an O, run bfs and set 
        // connected O's to Y
        // go through board, set O's to X, and Y's to O
        int rows = board.size();
        int cols = board[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        auto bfs = [&](int start_i, int start_j) {
            if (board[start_i][start_j] != 'O') {
                return;
            }
            board[start_i][start_j] = 'Y';
            std::queue<std::pair<int, int>> q;
            q.emplace(start_i, start_j);
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                for (auto& [d_i, d_j] : dirs) {
                    int n_i = d_i + i;
                    int n_j = d_j + j;
                    if (0 <= n_i && n_i < rows && 0 <= n_j && n_j < cols && board[n_i][n_j] == 'O') {
                        board[i][j] = 'Y';
                        q.emplace(n_i, n_j);
                    }
                }
            }
        };
        for (int i = 0; i < rows; i++) {
            bfs(i, 0);
            bfs(i, cols - 1);
        }
        for (int j = 0; j < cols; j++) {
            bfs(0, j);
            bfs(rows - 1, j);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
// @lc code=end

