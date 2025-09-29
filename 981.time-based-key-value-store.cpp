/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;
using TimestampPair = pair<int, string>;
class TimeMap {
public:
    unordered_map<string, vector<TimestampPair>> timeMap;
    TimeMap() {
         timeMap = unordered_map<string, vector<TimestampPair>>();
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<TimestampPair>& vec = timeMap[key];
        if (!vec.size())
            return "";
        int s = 0;
        int e = vec.size();
        string curr = "";
        while (s < e) {
            int m = s + (e - s) / 2;
            int t = vec[m].first;
            if (t == timestamp) {
                return vec[m].second;
            }
            if (t <= timestamp) {
                // this could still be a valid option
                curr = vec[m].second;
                s = m + 1;
            } else {
                e = m;
            }
        }
        return curr;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

