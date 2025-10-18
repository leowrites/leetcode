/*
 * @lc app=leetcode id=3349 lang=cpp
 *
 * [3349] Adjacent Increasing Subarrays Detection I
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // find start index of all increasing sequences
        auto isIncreasing = [&](int start) {
            for (int i = start; i < start + k - 1; i++) {
                if (nums[i] >= nums[i + 1]) return false;
            }
            return true;
        };
        for (int i = 0; i <= nums.size() - 2 * k; i++) {
            // check if i, i + k is increasing, and if i + k, i + 2k is increasing
            if (isIncreasing(i) && isIncreasing(i + k)) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

