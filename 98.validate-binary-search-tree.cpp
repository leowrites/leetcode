/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
  bool helper(TreeNode *root, long long upper, long long lower) {
    if (!root)
      return true;
    if (root->val >= upper || root->val <= lower) {
      return false;
    }
    return helper(root->right, upper, root->val) &&
           helper(root->left, root->val, lower);
  }
  bool isValidBST(TreeNode *root) {
    // start with upper=max, lower=min. goal is to gradually 
    // narrow down what values are allowed
    // going right = raising the minimum. going left = lowering the maximum
    return helper(root, std::numeric_limits<long long>::max(),
                  std::numeric_limits<long long>::min());
  }
};
// @lc code=end
