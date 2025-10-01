/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int currEmpty = numBottles;
        int total = numBottles;
        while (currEmpty >= numExchange) {
            // can exchange one more time
            total += currEmpty / numExchange;
            currEmpty = currEmpty / numExchange + currEmpty % numExchange;
        }
        return total;
    }
};
// @lc code=end

