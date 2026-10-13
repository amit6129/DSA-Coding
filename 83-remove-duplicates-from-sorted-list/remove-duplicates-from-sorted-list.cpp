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
    ListNode* deleteDuplicates(ListNode* head) {
        // If the list is empty or has only one node, no duplicates exist
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* current = head;
        
        // Traverse the linked list
        while (current != nullptr && current->next != nullptr) {
            // If the current node value matches the next node value
            if (current->val == current->next->val) {
                ListNode* duplicate = current->next;
                // Skip the duplicate node
                current->next = current->next->next;
                // Free the memory of the duplicate node
                delete duplicate;
            } else {
                // Otherwise, advance the current pointer
                current = current->next;
            }
        }
        
        return head;
    }
};
