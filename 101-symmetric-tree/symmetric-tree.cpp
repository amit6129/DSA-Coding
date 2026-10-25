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
private:
    bool isMirror(TreeNode* leftTree, TreeNode* rightTree) {
        // Base case: both subtrees are empty
        if (leftTree == nullptr && rightTree == nullptr) {
            return true;
        }
        
        // One subtree is empty while the other is not
        if (leftTree == nullptr || rightTree == nullptr) {
            return false;
        }
        
        // The node values must be equal, and their respective subtrees must mirror each other
        return (leftTree->val == rightTree->val)
            && isMirror(leftTree->left, rightTree->right)
            && isMirror(leftTree->right, rightTree->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric
        if (root == nullptr) {
            return true;
        }
        
        // Compare the left and right subtrees
        return isMirror(root->left, root->right);
    }
};
