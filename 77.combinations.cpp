/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    void helper(int n, int k, int c, vector<int>& curr, vector<vector<int>>& res) {
        if (k == 0) {
            // push back a copy of curr
            res.emplace_back(curr);
            return;
        }
        for (int i = c; i < n; i++) {
            curr.push_back(i + 1);
            helper(n, k - 1, i + 1, curr, res);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(n, k, 0, curr, res);
        return res;
    }
};
// @lc code=end

