/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    // returns the number of nodes visited
    void traverse(TreeNode* root, int k, int& res, int& nodesVisited) {
        if (!root) return;
        traverse(root->left, k, res, nodesVisited);
        nodesVisited++;
        if (nodesVisited == k) {
            res = root->val;
        }
        traverse(root->right, k, res, nodesVisited);
    }
    int kthSmallest(TreeNode* root, int k) {
        // is there a traversal that visits the smallest values first?
        // order: left, root, right
        int res;
        int nodesVisited = 0;
        traverse(root, k, res, nodesVisited);
        return res;
    }
};
// @lc code=end

