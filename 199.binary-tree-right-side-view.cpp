/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
#include <queue>
using namespace std;
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
    vector<int> rightSideView(TreeNode* root) {
         if (!root) {
            return {};
        }
        queue<pair<int, TreeNode*>> q;
        vector<int> res;
        q.push({1, root});
        while (!q.empty()) {
            const auto [index, node] = q.front();
            q.pop();
            // the first value in each index should be the rightmost element
            if (index > res.size()) {
                res.push_back(node->val);
            }
            if (node->right) {
                q.push({index + 1, node->right});
            }
            if (node->left) {
                q.push({index + 1, node->left});
            }
        }
        return res;
    }
};
// @lc code=end

