/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
#include <queue>
#include <tuple>
#include <unordered_map>
#include <utility>
using namespace std;
class FreqStack {
public:
    unordered_map<int, int> freqMap;
    // <freq, index, val>
    priority_queue<tuple<int, int, int>> freqQueue;
    int elementInStack = 0;

    FreqStack() {
    }
    
    void push(int val) {
        freqMap[val]++;
        elementInStack++;
        freqQueue.push({freqMap[val], elementInStack, val});
    }
    
    int pop() {
        int val = std::get<2>(freqQueue.top());
        freqQueue.pop();
        freqMap[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

