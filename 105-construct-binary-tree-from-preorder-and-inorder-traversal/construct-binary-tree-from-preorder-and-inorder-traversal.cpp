#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> inorder_map;
    int pre_idx = 0;

    TreeNode* helper(vector<int>& preorder, int in_left, int in_right) {
        // If the current subtree range is invalid, return nullptr
        if (in_left > in_right) {
            return nullptr;
        }

        // Pick the current root value from preorder and advance the index
        int root_val = preorder[pre_idx++];
        TreeNode* root = new TreeNode(root_val);

        // Get the index of the root from inorder to split left and right subtrees
        int pivot = inorder_map[root_val];

        // Build the left subtree, then the right subtree
        root->left = helper(preorder, in_left, pivot - 1);
        root->right = helper(preorder, pivot + 1, in_right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorder_map.clear();
        pre_idx = 0;
        
        // Map values to their indices in inorder for O(1) lookups
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        return helper(preorder, 0, inorder.size() - 1);
    }
};
