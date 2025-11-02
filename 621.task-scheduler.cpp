/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // after a task has been executed, it cannot be scheduled 
        // and must added to a cooldown queue
        // coolDownQueue = [[cooldown, frequency (decrease), task]]
        //  - use a min heap for cooldown to prioritize task that can be scheduled the earliest
        // readyQueue = [[taskCount, task]] 
        //  - use a max heap for taskCount to prioritize task with higher frequency

        // for the comparator: taskQ -> prioritize more frequent element
        priority_queue<pair<int, char>> taskQ;
        // cooldownQ -> prioritize smallest time
        priority_queue<tuple<size_t, int, char>, vector<tuple<size_t, int, char>>, greater<tuple<size_t, int, char>>> cooldownQ;
        unordered_map<char, int> taskFreq;
        for (auto& t: tasks) {
            taskFreq[t]++;
        }
        for (auto& [k, v]: taskFreq) {
            taskQ.emplace(v, k);
        }
        size_t t = 0;
        while (!taskQ.empty() || !cooldownQ.empty()) {
            auto [freq, task] = taskQ.top();
            taskQ.pop();
            t++;
            if (freq - 1 > 0) {
                cooldownQ.emplace(t + n, freq - 1, task);
            }
            if (!cooldownQ.empty()) {
                t = std::max(t, std::get<0>(cooldownQ.top()));
                while (!cooldownQ.empty() && std::get<0>(cooldownQ.top()) == t) {
                    // pop and add to taskQ
                    auto [_, f, task] = cooldownQ.top();
                    cooldownQ.pop();
                    taskQ.emplace(f, task);
                }
            }
        }
        return t;
    }
};
// @lc code=end

