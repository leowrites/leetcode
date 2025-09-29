/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // by modifying:
        // 1. for each num n, use n - 1 as the index. if current index is not n - 1, but the value
        // at n - 1 is n, then we return n
        // at each index, repeat
        // if the value is already at the correct index, continue
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i + 1) {
                continue;
            }
            int current_index = i - 1;
            int current_val = nums[current_index];
            while (current_val != current_index + 1) {
                current_index = nums[current_val];
                nums[current_val] = current_val;
            }
        }
    }
};
// @lc code=end

