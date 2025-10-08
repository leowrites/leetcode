/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (const auto c: s) {
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            pq.push({it->second, it->first});
        }
        string res;
        while (!pq.empty()) {
            // if all elements have the same freq and the top is the same
            // as the last character, need the second most frequent element
            pair<int, char> top;
            if (!res.empty() && pq.top().second == res.back()) {
                top = std::move(pq.top());
                pq.pop();
            }
            if (!pq.empty()) {
                auto [freq, c] = pq.top();
                pq.pop();
                res.push_back(c);
                freq--;
                if (freq > 0) {
                    pq.push({freq, c});
                }
                pq.push(top);
            } else {
                return "";
            }
        }
        return res;
    }
};
// @lc code=end

