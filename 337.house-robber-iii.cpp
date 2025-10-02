/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <algorithm>
#include <utility>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  std::pair<int, int> helper(TreeNode* root) {
    if (!root) {
        return {0, 0};
    }
    // let 0th = robs current, 1st be does not rob
    auto robLeft = helper(root->left);
    auto robRight = helper(root->right);

    int robCurrent = root->val + robLeft.second + robRight.second;
    int doNotRobCurrent = robLeft.first + robRight.first;
    return {robCurrent, doNotRobCurrent};
  }
  int rob(TreeNode *root) {
    auto res = helper(root);
    return std::max(res.first, res.second);
  }
};
// @lc code=end
