/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */

#include <queue>
#include <string>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        using T = pair<int, char>;
        std::priority_queue<T, vector<T>, less<T>> pq;
        if (a > 0) {
            pq.emplace(a, 'a');
        }
        if (b > 0) {
            pq.emplace(b, 'b');
        }
        if (c > 0) {
            pq.emplace(c, 'c');
        }
        while (!pq.empty()) {
            // pop top
            // see if last two is same
            // same -> pop another 
            // different -> append current
        }
    }
};
// @lc code=end

