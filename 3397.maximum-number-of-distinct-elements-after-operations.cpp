/*
 * @lc app=leetcode id=3397 lang=cpp
 *
 * [3397] Maximum Number of Distinct Elements After Operations
 */

// @lc code=start
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // for each element, we should try to remove as much from it as possible
        // if curr == prev, set curr to prev + 1 if in range, or just add it to a set
        int count = 0, prev = INT_MIN;
        for (auto n: nums) {
            // the current number is in [n - k, n + k], and it should be prev + 1 because
            // we are greedy
            int curr = min(max(n - k, prev + 1), n + k);
            if (curr > prev) {
                count++;
                prev = curr;
            }
        }
        return count;
    }
};
// @lc code=end

