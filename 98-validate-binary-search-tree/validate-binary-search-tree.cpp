class Solution {
private:
    // Helper function using long long to avoid integer overflow from INT_MIN/INT_MAX constraints
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (node == nullptr) {
            return true;
        }
        
        // The current node's value must strictly fall within the allowed range
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        
        // Left child must be less than current node's value (updates max bound)
        // Right child must be greater than current node's value (updates min bound)
        return validate(node->left, minVal, node->val) && 
               validate(node->right, node->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        // Initialize with values outside the standard 32-bit signed integer range
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};
