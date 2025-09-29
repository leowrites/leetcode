/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        while (s < e) {
            int k = s + (e - s) / 2;
            int hours = 0;
            for (int pile : piles) {
                hours += (pile + k - 1) / k; // Equivalent to ceil(pile / (double)k)
            }
            if (hours > h) {
                s = k + 1;
            } else {
                e = k;
            }
        }
        return s;
    }
};
// @lc code=end

