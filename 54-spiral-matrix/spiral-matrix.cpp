#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        std::vector<int> ans;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        
        while (top <= bottom && left <= right) {
            // 1. Move right across the top row
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            
            // 2. Move down the rightmost column
            for (int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            // Check to ensure we are still inside valid boundaries
            if (top <= bottom) {
                // 3. Move left across the bottom row
                for (int i = right; i >= left; --i) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if (left <= right) {
                // 4. Move up the leftmost column
                for (int i = bottom; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return ans;
    }
};
