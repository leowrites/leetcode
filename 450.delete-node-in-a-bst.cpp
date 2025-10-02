/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) {
            if (root->left) {
                TreeNode* leftNode = root->left;
                TreeNode* rightNode = root->right;
                root = leftNode;
                root->left = leftNode->left;
                root->right = leftNode->right;
                if (root->right) {
                    root->right->right = rightNode;
                } else {
                    root->right = rightNode;
                }
                return root;
            } else if (root->right) {
                TreeNode* leftNode = root->left;
                TreeNode* rightNode = root->right;
                root = rightNode;
                root->left = rightNode->left;
                root->right = rightNode->right;
                if (root->left) {
                    root->left->left = leftNode;
                } else {
                    root->left = leftNode;
                }
                return root;
            } else {
                return nullptr;
            }
        }
        TreeNode* left = deleteNode(root->left, key);
        root->left = left;
        TreeNode* right = deleteNode(root->right, key);
        root->right = right;
        return root;
    }
};
// @lc code=end

