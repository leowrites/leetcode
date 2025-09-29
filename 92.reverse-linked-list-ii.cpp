/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy = ListNode();
        dummy.next = head;
        ListNode *beforeStart = &dummy;
        ListNode *start = head;
        for (int i = 0; i < left - 1; i++) {
            beforeStart = start;
            start = start->next;
        }
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        ListNode *curr = start;
        for (int i = 0; i < right - left + 1; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        beforeStart->next = prev;
        start->next = curr;
        return dummy.next;
    }
};
// @lc code=end

