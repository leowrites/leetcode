/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
#include <cassert>
#include <cctype>
using namespace std;
#include <string>
#include <vector>
class Solution {
public:
    string decodeString(string s) {
        vector<string> stack;
        int currNum = 0;
        string currString = "";
        for (const auto& c : s) {
            if (c == '[') {
                stack.push_back(currString);
                stack.push_back(to_string(currNum));

                currString = "";
                currNum = 0;
            } else if (c == ']') {
                int num = stoi(stack.back());
                stack.pop_back();
                string str = std::move(stack.back());
                stack.pop_back();
                
                // Use more efficient string operations
                string result = std::move(str);
                result.reserve(result.size() + currString.size() * num);
                
                // More efficient than loop: repeat string num times
                for (int i = 0; i < num; i++) {
                    result.append(currString);
                }
                currString = std::move(result);
            } else if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            } else {
                currString += c;
            }
        }
        return currString;
    }
};
// @lc code=end

