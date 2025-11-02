/*
 * @lc app=leetcode id=2239 lang=cpp
 *
 * [2239] Find Closest Number to Zero
 */

// @lc code=start
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <vector>

using namespace std;
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int smallestSoFar = std::numeric_limits<int>::max();
        for (auto &n: nums) {
            if (abs(n) == abs(smallestSoFar)) {
                smallestSoFar = max(n, smallestSoFar);
                continue;
            }
            if (abs(n) < abs(smallestSoFar)) {
                smallestSoFar = n;
            }
        }
        return smallestSoFar;
    }
};
// @lc code=end

