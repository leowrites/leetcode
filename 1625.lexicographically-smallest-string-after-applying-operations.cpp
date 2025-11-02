/*
 * @lc app=leetcode id=1625 lang=cpp
 *
 * [1625] Lexicographically Smallest String After Applying Operations
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        std::unordered_set<string> generated;
        std::queue<string> queue;
        generated.insert(s);
        queue.push(s);
        string smallest = s;
        while (!queue.empty()) {
            string str = queue.front();
            queue.pop();
            if (str < smallest) {
                smallest = str;
            }
            string str1 = str;
            for (int i = 1; i < str1.size(); i += 2) {
                str1[i] = (str[i] - '0' + a) % 10 + '0';
            }
            if (generated.find(str1) == generated.end()) {
                queue.push(str1);
                generated.insert(str1);
            }
            // rotate values by putting str2[b + 1:] + str2[:b] 
            string rotated = str.substr(str.size() - b) + str.substr(0, str.size() - b);
            if (generated.find(rotated) == generated.end()) {
                queue.push(rotated);
                generated.insert(rotated);
            }
        }
        return smallest;
    }
};
// @lc code=end

