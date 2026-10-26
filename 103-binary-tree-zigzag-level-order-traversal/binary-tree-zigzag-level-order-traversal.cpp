#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        
        // Flag to track the traversal direction (true = left-to-right, false = right-to-left)
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            // Pre-allocate space for the current level's nodes
            vector<int> currentLevel(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Find the correct position to fill based on the direction flag
                int index = leftToRight ? i : (levelSize - 1 - i);
                currentLevel[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(currentLevel);
            // Flip the flag for the next level
            leftToRight = !leftToRight;
        }

        return result;
    }
};
