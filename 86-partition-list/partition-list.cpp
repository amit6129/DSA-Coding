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
    ListNode* partition(ListNode* head, int x) {
        // Create temporary dummy nodes for the two partitions
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);
        
        // Pointers to track the running tail of each partition
        ListNode* lessTail = lessHead;
        ListNode* greaterTail = greaterHead;
        
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                lessTail->next = curr;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = curr;
                greaterTail = greaterTail->next;
            }
            curr = curr->next;
        }
        
        // Important: Cut off any remaining chain elements to prevent cycles
        greaterTail->next = nullptr;
        
        // Connect the end of the 'less' partition to the start of the 'greater' partition
        lessTail->next = greaterHead->next;
        
        // Save the actual new head of the list
        ListNode* newHead = lessHead->next;
        
        // Free memory for dummy nodes
        delete lessHead;
        delete greaterHead;
        
        return newHead;
    }
};
