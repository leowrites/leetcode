/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
class Solution {
public:
    int totalMoney(int n) {
        // figure out how many weeks + days 
        int weeks = n / 7;
        int days = n % 7;
        double sum = 0;
        for (int i = 0; i < weeks; i++) {
            sum += (7.0 / 2) * (i + 1 + i + 7);
        }
        for (int i = 0; i < days; i++) {
            sum += weeks + i + 1;
        }
        return sum;
    }
};
// @lc code=end

