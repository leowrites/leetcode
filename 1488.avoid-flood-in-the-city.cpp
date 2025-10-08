/*
 * @lc app=leetcode id=1488 lang=cpp
 *
 * [1488] Avoid Flood in The City
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        queue<int> dries;
        vector<int> res(rains.size(), -1);
        unordered_map<int, bool> full;
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                dries.push(i);
            } else if (full.find(rains[i]) == full.end()) {
                full[rains[i]] = i;
            } else if (full[rains[i]] && !dries.empty()&& dries.front() > full[rains[i]]) {
                res[dries.front()] = rains[i];
                full[rains[i]] = i;
                dries.pop();
            } else {
                return {};
            }
        }
        while (!dries.empty()) {
            res[dries.front()] = 1;
            dries.pop();
        }
        return res;
    }
};
// @lc code=end

