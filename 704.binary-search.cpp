/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size();
        while (s < e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return -1;
    }
};
// @lc code=end

