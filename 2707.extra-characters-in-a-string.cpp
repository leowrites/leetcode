/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        // dp or greedy?
        // 1. build trie
        // 2. greedily take the longest possible substring
        // why is this optimal? it's not
        // leetscoder with [leets, scoder] would return 6
        // but it should be 5
        // similar to wordbreak
        // wordbreak -> is it possible at each index?
        // know by checking if it matches a word, then
        // accumulate chars while it does not match any string
        // in dictionary
        // matching at i -> recurse and start at i to find
        // next matching
        // no matching increment i by 1-> return # of chars that needs to be removed

    }
};
// @lc code=end

