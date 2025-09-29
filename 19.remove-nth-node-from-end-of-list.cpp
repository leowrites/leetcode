/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (!fast) {
            return head->next;
        }
        ListNode* prev = nullptr;
        ListNode* slow = head;
        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};
// @lc code=end

