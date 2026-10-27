#include <algorithm>

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
    int maxDepth(TreeNode* root) {
        // Base case: if the current node is null, its depth is 0
        if (root == nullptr) {
            return 0;
        }
        
        // Recursively find the depth of left and right subtrees,
        // and add 1 for the current node.
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
