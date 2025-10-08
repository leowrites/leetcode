/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class DoublyLinkedNode {
public:
    int val = 0;
    int key = 0;
    DoublyLinkedNode* next = nullptr;
    DoublyLinkedNode* prev = nullptr;
    DoublyLinkedNode(int key=0, int val=0) : key(key), val(val) {}
};

// when a node is recently used, move it to dummy->next
// to remove the least recently used node, remove the last node
// a hashmap will map key to the node, so the node can be moved
#include <unordered_map>
using namespace std;
class LRUCache {
public:
    int capacity;
    DoublyLinkedNode* headDummy;
    DoublyLinkedNode* tailDummy;
    unordered_map<int, DoublyLinkedNode*> map;

    LRUCache(int capacity): capacity(capacity) {
        headDummy = new DoublyLinkedNode(-1, -1);
        tailDummy = new DoublyLinkedNode(-1, -1);
        headDummy->next = tailDummy;
        tailDummy->prev = headDummy;
    }

    void removeNodeFromList(DoublyLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead(DoublyLinkedNode* node) {
        node->next = headDummy->next;
        headDummy->next->prev = node;
        headDummy->next = node;
        node->prev = headDummy;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        DoublyLinkedNode* node = map[key];
        removeNodeFromList(node);
        addNodeToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        DoublyLinkedNode* node;
        if (map.find(key) == map.end()) {
            node = new DoublyLinkedNode(key, value);
        } else {
            node = map[key];
            node->val = value;
            removeNodeFromList(node);
        }
        addNodeToHead(node);
        map[key] = headDummy->next;
        if (map.size() > capacity) {
            DoublyLinkedNode* lastNode = tailDummy->prev;
            removeNodeFromList(lastNode);
            map.erase(lastNode->key);
            delete lastNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

