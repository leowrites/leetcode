/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        unordered_map<int, Node*> valueToNode;
        queue<Node*> q({node});
        Node* head = new Node(node->val);
        valueToNode[node->val] = head; 
        while (!q.empty()) {
            const auto node = q.front();
            Node* newNode;
            q.pop();
            auto res = valueToNode.find(node->val);
            if (res == valueToNode.end()) {
                newNode = new Node(node->val);
            } else {
                newNode = res->second;
            }
            for (const auto &nei : node->neighbors) {
                Node* newNei;
                auto neiRes = valueToNode.find(nei->val);
                if (neiRes == valueToNode.end()) {
                    newNei = new Node(nei->val);
                    valueToNode[nei->val] = newNei;
                    q.push(nei);
                } else {
                    newNei = neiRes->second;
                }
                if (newNode->val < newNei->val) {
                    newNode->neighbors.push_back(newNei);
                    newNei->neighbors.push_back(newNode);
                }
            }
        }
        return head;
    }
};
// @lc code=end

