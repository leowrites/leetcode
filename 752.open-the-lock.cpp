/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
#include <queue>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }
        std::unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        if (deadendsSet.find("0000") != deadendsSet.end()) {
            return -1;
        }
        std::unordered_set<string> seen;
        queue<pair<string, int>> q;
        q.emplace("0000", 0);
        seen.insert("0000");
        while (!q.empty()) {
            auto [s, turns] = q.front();
            q.pop();
            // valid combinations: turn each of the 4 digits
            for (int i = 0; i < 4; i++) {
                //  - not in seen
                //  - not in deadend
                //  - if == target, return
                string left = s;
                left[i] = char((left[i] - '0' + 1) % 10 + '0');
                if (left == target) {
                    return turns + 1;
                }
                if (seen.find(left) == seen.end() && deadendsSet.find(left) == deadendsSet.end()) {
                    seen.insert(left);
                    q.emplace(left, turns + 1);
                }

                string right = s;
                if (right[i] - '0' - 1 < 0) {
                    right[i] = '9';
                } else {
                    right[i] = (right[i] - '0' - 1) + '0';
                }
                if (right == target) {
                    return turns + 1;
                }
                if (seen.find(right) == seen.end() && deadendsSet.find(right) == deadendsSet.end()) {
                    seen.insert(right);
                    q.emplace(right, turns + 1);
                }
            }
        }
        return -1;
    }
};
// @lc code=end

