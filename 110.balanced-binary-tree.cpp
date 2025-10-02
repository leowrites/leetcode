/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
#include <cstdlib>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
    int height(TreeNode* root, bool& isBalanced) {
        if (!root) return 0;
        int left = height(root->left, isBalanced);
        int right = height(root->right, isBalanced);
        if (isBalanced) {
            isBalanced = abs(left - right) <= 1;
        }
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        height(root, isBalanced);
        return isBalanced;
    }
};
// @lc code=end

