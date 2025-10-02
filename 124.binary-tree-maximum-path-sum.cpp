/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
#include <limits>

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
    int helper(TreeNode* root, int& maxSumSoFar) {
        if (!root) return 0;
        int left = std::max(0, helper(root->left, maxSumSoFar));
        int right = std::max(0, helper(root->right, maxSumSoFar));
        maxSumSoFar = std::max(maxSumSoFar, left + right + root->val);
        return std::max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSumSoFar = std::numeric_limits<int>::min();
        helper(root, maxSumSoFar);
        return maxSumSoFar;
    }
};
// @lc code=end

