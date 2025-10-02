/*
 * @lc app=leetcode id=3100 lang=cpp
 *
 * [3100] Water Bottles II
 */

// @lc code=start
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = numBottles;
        int numEmpty = numBottles;
        numBottles = 0;
        while (numBottles > 0 || numEmpty >= numExchange) {
            while (numEmpty >= numExchange) {
                numEmpty -= numExchange;
                numBottles += 1;
                numExchange++;
            }
            drank += numBottles;
            numEmpty += numBottles;
            numBottles = 0;
        }
        return drank;
    }
};
// @lc code=end

