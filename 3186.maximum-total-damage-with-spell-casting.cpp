/*
 * @lc app=leetcode id=3186 lang=cpp
 *
 * [3186] Maximum Total Damage With Spell Casting
 */

// @lc code=start
#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        std::unordered_map<int, long> freq;
        std::vector<long long> powers;
        for (auto p: power) {
            freq[p]++;
        }
        for (auto p: freq) {
            powers.push_back(p.first);
        }
        std::vector<long long> dp(powers.size(), 0);
        std::sort(powers.begin(), powers.end());
        for (int i = 0; i < dp.size(); i++) {
            long long bestPrev = 0;
            if (i > 0 && abs(powers[i - 1] - powers[i]) > 2) {
                bestPrev = max(bestPrev, dp[i - 1]);
            }
            if (i > 1 && abs(powers[i - 2] - powers[i]) > 2) {
                bestPrev = max(bestPrev, dp[i - 2]);
            }
            if (i > 2) {
                bestPrev = max(bestPrev, dp[i - 3]);
            }
            dp[i] = bestPrev + powers[i] * freq[powers[i]];
            if (i > 0) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
            if (i > 1) {
                dp[i] = max(dp[i], dp[i - 2]);
            }
        }
        return dp.back();
    }
};
// @lc code=end

