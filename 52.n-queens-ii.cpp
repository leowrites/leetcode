/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    // maybe using vector<vector<int>> is very slow since access is not contiguous
   bool isAllowed(int row, int col, vector<vector<int>>& board, vector<int>& cols) {
        // we can maintain row/col for fast check
        if (cols[col]) {
            return false;
        }
        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 1}};
        for (auto [d_i, d_j]: dirs) {
            int currRow = row;
            int currCol = col;
            while (0 <= currRow + d_i && currRow + d_i < board.size() && 0 <= currCol + d_j && currCol + d_j < board.size()) {
                currRow += d_i;
                currCol += d_j;
                if (board[currRow][currCol] == 1) {
                    return false;
                }
            }
        }
        return true;
    }
    void bt(int row, vector<vector<int>>& board, int queensPlaced, int &solutions, vector<int>& cols) {
        if (queensPlaced == board.size()) {
            solutions += 1;
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            if (isAllowed(row, col, board, cols)) {
                board[row][col] = 1;
                cols[col] = 1;
                bt(row + 1, board, queensPlaced + 1, solutions, cols);
                cols[col] = 0;
                board[row][col] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<int> cols(n, 0);
        int solutions = 0;
        bt(0, board, 0, solutions, cols);
        return solutions;
    }
};
// @lc code=end

