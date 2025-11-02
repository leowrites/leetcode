/*
 * @lc app=leetcode id=3461 lang=cpp
 *
 * [3461] Check If Digits Are Equal in String After Operations I
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        string prev = s;
        string curr = "";
        while (prev.size() > 2) {
            for (int i = 0; i < prev.size() - 1; i++) {
                int num1 = prev[i] - '0';
                int num2 = prev[i + 1] - '0';
                curr += (char)((num1 + num2) % 10 + '0');
            }
            prev = curr;
            curr = "";
        }
        return prev[0] == prev[1];
    }
};
// @lc code=end

