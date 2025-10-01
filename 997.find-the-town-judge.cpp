/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n, 0);
        vector<int> outDegree(n, 0);
        for (auto & pair: trust) {
            int person1 = pair[0] - 1;
            int person2 = pair[1] - 1;
            inDegree[person2]++;
            outDegree[person1]++;
        }
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

