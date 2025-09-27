/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int s = 0;
        int e = x / 2;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            // we cannot use int because the result may overflow int
            long long sq = (long long)mid * mid;
            long long sqPrev = (long long)(mid - 1) * (mid - 1);
            // if the current result > x but the next is <=, we should return next
            if (sq > x && sqPrev <= x) {
                return mid - 1;
            } else if (sq > x) {
                e = mid - 1;
            } else if (sq == x) {
                return mid;
            } else {
                s = mid + 1;
            }
        }
        return e;
    }
};
// @lc code=end

