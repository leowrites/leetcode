/*
 * @lc app=leetcode id=3346 lang=cpp
 *
 * [3346] Maximum Frequency of an Element After Performing Operations I
 */

// @lc code=start
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> valFreqs{};
        for (const auto& n: nums) {
            if (valFreqs.empty() || n != valFreqs.back().first) {
                valFreqs.emplace_back(n, 1);
            } else if (n == valFreqs.back().first) {
                valFreqs.back().second++;
            }
        }

        // maintain dynamic sliding widow with max window size of numOperations
        int maxFreq = 0;
        int currInWindow = 0;
        int left = 0;
        for (int right = 0; right < valFreqs.size(); right++) {
            currInWindow += valFreqs[right].second;
            while (valFreqs[right].first - valFreqs[left].first > 2 * k) {
                currInWindow -= valFreqs[left].second;
                left++;
            }
            int canMake = min(currInWindow, valFreqs[right].second + numOperations);
            maxFreq = max(maxFreq, canMake);
        }
        return maxFreq;
    }
};
// @lc code=end

