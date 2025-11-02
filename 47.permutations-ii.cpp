/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    size_t numSize;
    void helper(vector<int>& curr, unordered_map<int, int>& count, vector<vector<int>>& res) {
        if (numSize == curr.size()) {
            res.emplace_back(curr);
            return;
        }
        for (auto it = count.begin(); it != count.end(); it++) {
            if (it->second > 0) {
                curr.emplace_back(it->first);
                it->second--;
                helper(curr, count, res);
                it->second++;
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        numSize = nums.size();
        unordered_map<int, int> counter;
        vector<vector<int>> res;
        vector<int> curr;
        for (auto& n: nums) {
            counter[n]++;
        }
        helper(curr, counter, res);
        return res;
    }
};
// @lc code=end

