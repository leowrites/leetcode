/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int perimeter = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    // Start with 4 edges, subtract for each adjacent land cell
                    perimeter += 4;
                    if (i > 0 && grid[i-1][j] == 1) perimeter--;           // up
                    if (i < rows-1 && grid[i+1][j] == 1) perimeter--;      // down  
                    if (j > 0 && grid[i][j-1] == 1) perimeter--;           // left
                    if (j < cols-1 && grid[i][j+1] == 1) perimeter--;      // right
                }
            }
        }
        
        return perimeter;
    }
};
// @lc code=end

