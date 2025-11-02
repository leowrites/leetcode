/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

// @lc code=start
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // 1. sort tasks by starting time, use an index to track tasks
        //      not yet added to the processing queue
        // 2. min priority queue <shortest_duration, index_of_task>
        // since we need to return the order:
        //      a. construct new vector [enqueueTime, processingTime, index]
        //      b. min pq using enqueueTime
        // let i = 0
        // let time = tasks[0]
        // let pq = []
        // let sortedArray = tasks.sorted()
        // let res = []
        // while i < len(tasks)
        //      while i < len(tasks) and tasks[i].start_time <= time
        //          add [tasks[i].end_time - tasks[i].start_time, i] to pq
        //          i++
        //      process a single task from pq
        //      set time to tasks[i].end_time
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> waitQ;
        priority_queue<T, vector<T>, greater<T>> readyQ;
        vector<int> res;
        for (int i = 0; i < tasks.size(); i++) {
            waitQ.emplace(tasks[i][0], i);
        }
        size_t time = waitQ.top().first;
        while (!waitQ.empty() || !readyQ.empty()) {
            while (!waitQ.empty() && waitQ.top().first <= time) {
                auto [enqueueTime, index] = waitQ.top();
                readyQ.emplace(tasks[index][1], index);
                waitQ.pop();
            }
            if (readyQ.empty()) {
                time = waitQ.top().first;
                continue;
            }
            auto [shortest_duration, index] = readyQ.top();
            readyQ.pop();
            time += shortest_duration;
            res.push_back(index);
        }
        return res;
    }
};
// @lc code=end

