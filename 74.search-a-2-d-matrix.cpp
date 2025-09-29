/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int s = 0;
        int e = rows;
        int rowIndex = -1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            int first = matrix[mid][0];
            int last = matrix[mid].back();
            if (first <= target && target <= last) {
                rowIndex = mid;
                break;
            } else if (target < first) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        if (rowIndex == -1) {
            return false;
        }
        s = 0;
        e = cols;
        vector<int>& row = matrix[rowIndex];
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (row[mid] == target) {
                return true;
            } else if (target < row[mid]) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

