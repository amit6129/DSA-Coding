#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        // Initialize an n x n matrix with 0
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int num = 1;
        
        while (top <= bottom && left <= right) {
            // 1. Move from left to right across the top boundary
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++; // Move top boundary down
            
            // 2. Move from top to bottom down the right boundary
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--; // Move right boundary left
            
            // 3. Move from right to left across the bottom boundary
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                bottom--; // Move bottom boundary up
            }
            
            // 4. Move from bottom to top up the left boundary
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                left++; // Move left boundary right
            }
        }
        
        return matrix;
    }
};
