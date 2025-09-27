/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    double dist(vector<int>& p1, vector<int>& p2) {
        return sqrt(pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        // for every pair of points, calculate the area and return the max
        // area of triangle = (a * b) / 2
        double maxArea = 0;
        for (int i = 0; i < points.size(); i++) {
            vector<int>& p1 = points[i];
            for (int j = i + 1; j < points.size(); j++) {
                vector<int>& p2 = points[j];
                for (int z = j + 1; z < points.size(); z++) {
                    vector<int>& p3 = points[z];
                    double len1 = dist(p1, p2);
                    double len2 = dist(p1, p3);
                    double len3 = dist(p2, p3);
                    double perimeter = (len1 + len2 + len3) / 2;
                    double area = sqrt(perimeter * (perimeter * len1) * (perimeter * len2) * (perimeter * len3));
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end

