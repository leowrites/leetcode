/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int curr, unordered_set<int>& visited, vector<int> path, unordered_map<int, unordered_set<int>>& graph, vector<int>& res) {
        for (auto& nei: graph[curr]) {
            // check if a node is in path but is not the parent
            for (int i = 0; i < path.size(); i++) {
                if (path[i] == nei && i != path.size() - 1) {
                    res = {curr, nei};
                    return;
                }
            }
            if (visited.find(nei) != visited.end()) {
                path.push_back(nei);
                visited.insert(nei);
                dfs(nei, visited, path, graph, res);
                path.pop_back();
            }
        }
        return;
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i < edges.size(); i++) {
            vector<int>& edge = edges[i];
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        int start = 0;
        int minDegree = 3;
        for (auto& [k, v]: graph) {
            if (v.size() <= minDegree) {
                minDegree = v.size();
                start = k;
            }
        }

        unordered_set<int> visited;
        vector<int> res;
        vector<int> path;
        visited.insert(start);
        path.push_back(start);
        dfs(start, visited, path, graph, res);        
        return res;
    }
};
// @lc code=end

