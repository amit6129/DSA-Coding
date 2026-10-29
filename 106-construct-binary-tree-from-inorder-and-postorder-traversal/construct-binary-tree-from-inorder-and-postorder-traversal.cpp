#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, int> inorder_map;
    int post_idx;

    TreeNode* buildTreeHelper(vector<int>& postorder, int in_left, int in_right) {
        if (in_left > in_right) {
            return nullptr;
        }

        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);
        post_idx--;

        int root_in_idx = inorder_map[root_val];

        // Build the right subtree first because we are moving 
        // backward through the postorder array
        root->right = buildTreeHelper(postorder, root_in_idx + 1, in_right);
        root->left = buildTreeHelper(postorder, in_left, root_in_idx - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inorder_map.clear();
        post_idx = postorder.size() - 1;

        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        return buildTreeHelper(postorder, 0, inorder.size() - 1);
    }
};
