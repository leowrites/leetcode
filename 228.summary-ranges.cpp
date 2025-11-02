/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<string> res;
        if (nums.size() == 0) {
            return res;
        }
        int currStart = nums[0];
        int currEnd = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (currEnd != currStart) {
                    res.push_back(to_string(currStart) + "->" + to_string(currEnd));
                } else {
                    res.push_back(to_string(currStart));
                }
                currStart = nums[i];
                currEnd = nums[i];
            } else {
                currEnd = nums[i];
            }
        }
        if (currEnd != currStart) {
            res.push_back(to_string(currStart) + "->" + to_string(currEnd));
        } else {
            res.push_back(to_string(currStart));
        }
        return res;
    }
};
// @lc code=end

