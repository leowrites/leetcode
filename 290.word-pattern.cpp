/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    def wordPattern(self, pattern: str, s: str) -> bool:
        l = s.split(" ")
        if len(l) != len(pattern): 
            return False
        patternToStr = {}
        strToPattern = {}
        for i in range(len(pattern)):
            c = pattern[i]
            string = l[i]
            if c in patternToStr and patternToStr[c] != string or string in strToPattern and strToPattern[string] != c:
                return False
            patternToStr[c] = string
            strToPattern[string] = c
        return True
};
// @lc code=end

