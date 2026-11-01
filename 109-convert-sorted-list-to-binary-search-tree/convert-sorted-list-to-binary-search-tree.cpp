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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        
        // Find the middle element and disconnect the left half
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Disconnect the left half to separate subproblems
        if (prev) {
            prev->next = nullptr;
        }
        
        // 'slow' is now the middle element and the root of this subtree
        TreeNode* root = new TreeNode(slow->val);
        
        // Recursively build left and right subtrees
        root->left = sortedListToBST(head);      // Left sublist is from head to prev
        root->right = sortedListToBST(slow->next); // Right sublist is from slow->next onwards
        
        return root;
    }
};
