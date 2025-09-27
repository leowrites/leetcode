/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
#include <cstddef>
#include <vector>
using namespace std;
#include <string>
class Solution {
public:
    void addToStack(vector<string> & stack, const string & curr) {
        if (curr == "..") {
            if (stack.size() > 0) {
                stack.pop_back();
            }
        } else if (curr != ".") {
            stack.push_back(curr);
        }
    }
    string simplifyPath(string path) {
        vector<string> stack;
        string curr = "";
        for (const auto & c : path) {
            if (c == '/' && curr.size() > 0) {
                addToStack(stack, curr);
                curr = "";
            } else if (c != '/') {
                curr += c;
            }
        }
        if (curr.size() > 0) {
            addToStack(stack, curr);
        }
        // construct the path
        string canonicalPath = "/";
        for (size_t i = 0; i < stack.size(); i++) {
            canonicalPath += stack[i];
            if (i < stack.size() - 1) {
                canonicalPath += "/";
            }
        }
        return canonicalPath;
    }
};
// @lc code=end

