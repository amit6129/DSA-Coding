#include <vector>

class Solution {
public:
    void inorder(TreeNode* root, std::vector<int>& ans) {
        if (root == nullptr) return;
        
        inorder(root->left, ans);   // Traverse Left
        ans.push_back(root->val);   // Visit Root
        inorder(root->right, ans);  // Traverse Right
    }

    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
