class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Detect a violation (previous node value is greater than or equal to current)
        if (prev && prev->val >= root->val) {
            // First violation: the incorrect node is the 'prev' node
            if (!first) {
                first = prev;
            }
            // Second violation (or if adjacent): the incorrect node is the 'root' node
            second = root;
        }

        // Move the track forward
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // Find the two swapped nodes
        inorder(root);

        // Swap their values back to fix the tree structure
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};
