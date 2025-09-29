/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *std::max_element(weights.begin(), weights.end());
        int e = std::accumulate(weights.begin(), weights.end(), 0);
        while (s < e) {
            int c = s + (e - s) / 2;
            int d = 0;
            int currWeight = 0;
            for (const auto& w : weights) {
                if (currWeight + w > c) {
                    d += 1;
                    currWeight = w;
                } else {
                    currWeight += w;
                }
            }
            if (currWeight > 0) {
                d += 1;
            }
            if (d > days) {
                s = c + 1;
            } else {
                e = c;
            }
        }
        return s;
    }
};
// @lc code=end

