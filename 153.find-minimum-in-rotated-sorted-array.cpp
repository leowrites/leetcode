/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        while (s < e) {
            if (nums[s] <= nums[e]) {
                return nums[s];
            }
            int mid = s + (e - s) / 2;
            if (nums[mid] >= nums[s]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        // loop terminates when s == e, so we can return either nums[s] or nums[e]
        return nums[s];
    }
};
// @lc code=end

