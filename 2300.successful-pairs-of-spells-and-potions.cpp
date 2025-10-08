/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end());
        std::vector<int> res;
        for (int i = 0; i < spells.size(); i++) {
            // if current spell is same as previous, use the result directly
            if (i > 0 && spells[i - 1] == spells[i]) {
                res.push_back(res.back());
                continue;
            }
            int s = spells[i];
            long long minimumPotion = ceil(static_cast<double>(success) / static_cast<double>(s));
            int start = 0, end = potions.size();
            int smallestIndex = end;
            while (start < end) {
                int mid = start + (end - start) / 2;
                if (potions[mid] < minimumPotion) {
                    start = mid + 1;
                } else {
                    smallestIndex = min(smallestIndex, mid);
                    end = mid;
                }
            }
            res.push_back(potions.size() - smallestIndex);
        }
        return res;
    }
};
// @lc code=end

