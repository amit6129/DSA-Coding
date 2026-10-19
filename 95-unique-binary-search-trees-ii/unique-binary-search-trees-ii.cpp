#include <vector>

class Solution {
public:
    std::vector<TreeNode*> generateTrees(int start, int end) {
        std::vector<TreeNode*> all_trees;
        
        // Base case: if start > end, no elements left to construct trees.
        // We add a nullptr to represent an empty child.
        if (start > end) {
            all_trees.push_back(nullptr);
            return all_trees;
        }

        // Pick each number 'i' in the range as the root
        for (int i = start; i <= end; ++i) {
            // Generate all possible left and right subtrees
            std::vector<TreeNode*> left_trees = generateTrees(start, i - 1);
            std::vector<TreeNode*> right_trees = generateTrees(i + 1, end);

            // Connect every left subtree with every right subtree under the root 'i'
            for (TreeNode* left : left_trees) {
                for (TreeNode* right : right_trees) {
                    TreeNode* current_root = new TreeNode(i);
                    current_root->left = left;
                    current_root->right = right;
                    all_trees.push_back(current_root);
                }
            }
        }
        return all_trees;
    }

    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTrees(1, n);
    }
};
