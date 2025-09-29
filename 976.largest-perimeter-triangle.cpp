/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace  std;;
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int maxPerimeter = 0;
        for (int i = nums.size() - 1; i > 1; --i) {
            if (nums[i] >= nums[i - 1] + nums[i - 2]) {
                continue;
            }
            return nums[i] + nums[i - 1] + nums[i - 2];
        }
        return 0;
    }
};
// @lc code=end

