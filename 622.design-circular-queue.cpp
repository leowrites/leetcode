/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start

class ListNode {
public:
    int val = 0;
    ListNode* next = nullptr;
    ListNode(int val=0, ListNode* next=nullptr);
};

class MyCircularQueue {
public:
    int maxSize;
    int currentSize;
    ListNode* head;
    ListNode* tail;
    MyCircularQueue(int k) {
        currentSize = 0;
        maxSize = k;
        head = new ListNode();
        ListNode* curr = head;
        for (int i = 1; i < maxSize; i++) {
            curr->next = new ListNode();
            curr = curr->next;
        }
        curr->next = head;
        tail = head;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (!isEmpty()) {
            tail = tail->next;
        }
        tail->val = value;
        currentSize++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = head->next;
        currentSize--;
        if (isEmpty()) {
            // We need this line:
            // if there is 1 element in the queue, head and tail points to the same position.
            // then we deque, which advances head, and tail is out of sync with head.
            tail = head;
        }
        return true;
    }
    
    int Front() {
        if (!isEmpty()) {
            return head->val;
        }
        return -1;
    }
    
    int Rear() {
        if (!isEmpty()) {
            return tail->val;
        }
        return -1;
    }
    
    bool isEmpty() {
        return currentSize == 0;
    }
    
    bool isFull() {
        return currentSize == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

