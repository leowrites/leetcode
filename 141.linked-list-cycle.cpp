/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // fast slow pointers. if two pointers meet, return the index of the first pointer?
        if (!head->next) {
            return false;
        }
        ListNode* fast = head->next->next;
        // if fast becomes nullptr, we should break and return false
        ListNode* slow = head->next;
        while (fast) {
            if (fast == slow) {
                return true;
            }
            if (!fast->next) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
// @lc code=end

