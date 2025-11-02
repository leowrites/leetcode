/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool bt(int i, int k, vector<int>& nums, vector<int>& subsets, int target) {
        if (i == nums.size()) {
            return true;
        }
        for (int j = 0; j < k; j++) {
            if (nums[i] + subsets[j] > target) {
                continue;
            }
            subsets[j] += nums[i];
            if (bt(i + 1, k, nums, subsets, target)) {
                return true;
            }
            subsets[j] -= nums[i];
            if (subsets[j] == 0) {
                break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum / k;
        if (sum % k != 0) {
            return false;
        }
        vector<int> subsets(k);
        return bt(0, k, nums, subsets, target);
    }
};
// @lc code=end

