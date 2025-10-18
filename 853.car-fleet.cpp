/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<pair<int, int>> cars(position.size());
        for (int i = 0; i < position.size(); i++) {
            cars.emplace_back(position[i], speed[i]);
        }
        sort(cars.begin(), cars.end());
        std::vector<double> times(position.size());
        for (auto& c: cars) {
            times.emplace_back((double)(target - c.first) / c.second);
        }
        int fleet = 0;
        while (times.size() > 1) {
            double lead = times.back();
            times.pop_back();
            if (lead < times.back()) {
                fleet++;
            } else {
                times.back() = lead;
            }
        }

        return fleet;
    }
};
// @lc code=end

