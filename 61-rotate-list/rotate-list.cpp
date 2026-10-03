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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 1. Handle edge cases: empty list, single node, or no rotation needed
        if (!head || !head->next || k == 0) {
            return head;
        }
        
        // 2. Compute the length of the list and find the tail node
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        // 3. Optimize k to handle cases where k >= length
        k = k % length;
        if (k == 0) {
            return head; // No rotation needed after modulo optimization
        }
        
        // 4. Link tail to head to form a circular loop
        tail->next = head;
        
        // 5. Find the new tail node (at position: length - k)
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }
        
        // 6. Set the new head and break the circular connection
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};
