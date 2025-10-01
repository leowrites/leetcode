/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
#include <vector>

using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            for (int j = 0; j < w1.size(); j++) {
                if (w2.size() < j + 1) {
                    return false;
                }
                size_t c1Index = order.find(w1[j]);
                size_t c2Index = order.find(w2[j]);
                if (c1Index < c2Index) {
                    break;
                } else if (c1Index > c2Index) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

