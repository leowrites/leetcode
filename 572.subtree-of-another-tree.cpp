/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
  bool isSameTree(TreeNode *root, TreeNode *subRoot) {
    if (!root && subRoot || root && !subRoot)
      return false;
    if (!root && !subRoot)
      return true;
    return root->val == subRoot->val && isSameTree(root->left, subRoot->left) &&
           isSameTree(root->right, subRoot->right);
  }
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!root) return false;  // Base case: can't find subtree in empty tree
    // Check current node, then recursively check left and right subtrees
    return isSameTree(root, subRoot) || 
           isSubtree(root->left, subRoot) || 
           isSubtree(root->right, subRoot);
  }
};
// @lc code=end
