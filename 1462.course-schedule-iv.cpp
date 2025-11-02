/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
  void dfs(int course, vector<int> &path,
           unordered_map<int, unordered_set<int>> &prerequisites, unordered_set<int> &seen,
           unordered_map<int, unordered_set<int>> &prereqToCourses) {
    for (auto &nei : prerequisites[course]) {
        // if course is already seen, skip
        if (seen.find(nei) != seen.end()) {
            prereqToCourses[course].insert(nei);
            set_union(
                prereqToCourses[course].begin(), prereqToCourses[course].end(),
                prereqToCourses[nei].begin(), prereqToCourses[nei].end(),
                std::back_inserter(prereqToCourses[course])
            );
            continue;
        }
        // each of the course in the path is a prereq to the neighbor
        for (auto &v : path) {
          prereqToCourses[v].insert(nei);
        }
        // mark as seen and add to path. Since there is no cycles, we don't need to check the path
        path.emplace_back(nei);
        seen.insert(nei);
        dfs(nei, path, prerequisites, seen, prereqToCourses);
        path.pop_back();
    }
  }

  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
};
// @lc code=end
