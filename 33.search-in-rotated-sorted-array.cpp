/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size();
        while (s < e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[m] > nums[s]) {
                if (nums[s] <= target && target < nums[m]) {
                    e = m;
                } else {
                    s = m + 1;
                }
            } else {
                if (nums[m] < target && target <= nums[e - 1]) {
                    s = m + 1;
                } else {
                    e = m;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

