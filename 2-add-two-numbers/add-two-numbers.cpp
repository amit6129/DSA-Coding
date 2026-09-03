
/** Amit Deshmukh 2
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(x) : val(x), next(nullptr) {}
 *     ListNode(x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head to anchor the result list
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;
        
        // Loop runs as long as there is data to process or a leftover carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate sum and update carry
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            // Create a new node with the current digit
            current->next = new ListNode(sum % 10);
            current = current->next;
            
            // Advance pointers if the lists have more nodes
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        // Save the actual head and delete the dummy node to prevent memory leaks
        ListNode* result = dummyHead->next;
        delete dummyHead; 
        
        return result;
    }
};
