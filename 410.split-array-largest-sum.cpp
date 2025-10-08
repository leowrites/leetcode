/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int start = *std::max_element(nums.begin(), nums.end());
        int end = std::accumulate(nums.begin(), nums.end(), 0);
        while (start < end) {
            int mid = start + (end - start) / 2;
            int accumulator = 0;
            int subarrayCount = 0;
            for (const auto & n: nums) {
                if (accumulator + n > mid) {
                    accumulator = n;
                    subarrayCount++;
                } else {
                    accumulator += n;
                }
            }
            if (accumulator > 0) subarrayCount++;
            if (subarrayCount > k) {
                // search for a larger min
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return end;
    }
};
// @lc code=end

