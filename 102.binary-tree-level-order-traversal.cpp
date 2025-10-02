/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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

#include <utility>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<pair<int, TreeNode*>> q;
        vector<vector<int>> res;
        q.push({1, root});
        while (!q.empty()) {
            const auto node = q.front();
            q.pop();
            if (node.first > res.size()) {
                res.push_back({node.second->val});
            } else {
                res[node.first - 1].push_back(node.second->val);
            }
            if (node.second->left)
                q.push({node.first + 1,node.second->left});
            if (node.second->right)
                q.push({node.first + 1,node.second->right});
        }
        return res;
    }
};
// @lc code=end

