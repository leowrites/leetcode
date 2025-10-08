/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int maxArea = 0;
        while (s < e) {
            int area = (e - s) * min(height[s], height[e]);
        }        
    }
};
// @lc code=end

