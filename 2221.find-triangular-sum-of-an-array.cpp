/*
 * @lc app=leetcode id=2221 lang=cpp
 *
 * [2221] Find Triangular Sum of an Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int i = nums.size(); i > 1; i--) {
            for (int j = nums.size() - 1; j > nums.size() - i; j--) {
                nums[j] = (nums[j - 1] + nums[j]) % 10;
            }
        }
        return nums[nums.size() - 1];
    }
};
// @lc code=end

