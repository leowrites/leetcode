/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start

#include <utility>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    // <val, index>
    using T = pair<int, int>;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> q;
        std::vector<int> res;
        res.reserve(nums.size() - k + 1);
        for (int e = 0; e < nums.size(); e++) {
            // e - k: if e == k, the first element is popped 
            while (!q.empty() && q.front() <= e - k) {
                q.pop_front();
            }
            // pop from the back because the current element is greater than them,
            // and will stay in the queue at least as long as them
            while (!q.empty() && nums[q.back()] < nums[e]) {
                q.pop_back();
            }
            q.push_back(e);
            // can append when e = k - 1
            if (e >= k - 1) {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};
// @lc code=end

