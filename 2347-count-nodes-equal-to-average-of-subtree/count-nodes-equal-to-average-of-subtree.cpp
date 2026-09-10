class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int matchingNodesCount = 0;
        calculateSubtree(root, matchingNodesCount);
        return matchingNodesCount;
    }

private:
    // Helper function returns a pair: {total_sum, node_count}
    std::pair<int, int> calculateSubtree(TreeNode* node, int& count) {
        if (!node) {
            return {0, 0};
        }

        // Postorder traversal: collect data from left and right subtrees
        auto leftDetails = calculateSubtree(node->left, count);
        auto rightDetails = calculateSubtree(node->right, count);

        // Compute total sum and node count for the current subtree
        int currentSum = leftDetails.first + rightDetails.first + node->val;
        int currentCount = leftDetails.second + rightDetails.second + 1;

        // C++ integer division naturally rounds down towards zero
        if (node->val == (currentSum / currentCount)) {
            count++;
        }

        return {currentSum, currentCount};
    }
};
