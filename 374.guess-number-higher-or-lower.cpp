/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int s = 0;
        int e = n;
        int guessN = (s + e) / 2;
        int res;
        while ((res = guess(guessN)) != 0) {
            if (res == 1) {
                s = guessN + 1;
            } else {
                e = guessN;
            }
            guessN = (s + e) / 2;
        }
        return guessN;
    }
};
// @lc code=end

