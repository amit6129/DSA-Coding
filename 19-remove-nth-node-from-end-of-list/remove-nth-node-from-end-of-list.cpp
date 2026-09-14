/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases like removing the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer so that there is a gap of n nodes between fast and slow
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // slow->next is the node to be deleted
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Free memory of the deleted node and dummy node
        delete nodeToDelete;
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};
