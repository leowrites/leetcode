/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start

#include <cmath>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double distanceToOrigin(const vector<int>& point) {
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        
        for (int i = 0; i < points.size(); ++i) {
            int dist = distanceToOrigin(points[i]);
            pq.push({dist, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> res;
        res.reserve(k);
        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return res;
    }
};
// @lc code=end

