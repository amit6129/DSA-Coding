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
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head != nullptr) {
            // If it's the start of a duplicate sequence
            if (head->next != nullptr && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Link prev to the node after the last duplicate
                prev->next = head->next;
            } else {
                // No duplicate, move prev forward
                prev = prev->next;
            }
            head = head->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
