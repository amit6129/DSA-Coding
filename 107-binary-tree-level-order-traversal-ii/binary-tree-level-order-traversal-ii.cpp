#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> current_level;
            
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                current_level.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(current_level);
        }
        
        // Reverse the top-down traversal to make it bottom-up
        reverse(result.begin(), result.end());
        return result;
    }
};
