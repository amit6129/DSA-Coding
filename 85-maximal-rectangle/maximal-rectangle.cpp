#include <vector>
#include <stack>
#include <algorithm>

class Solution {
private:
    // Helper function to find the largest rectangle in a 1D histogram
    int largestRectangleArea(const std::vector<int>& heights) {
        std::stack<int> st;
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; ++i) {
            int current_height = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && heights[st.top()] > current_height) {
                int height = heights[st.top()];
                st.pop();
                
                int width = st.empty() ? i : (i - st.top() - 1);
                max_area = std::max(max_area, height * width);
            }
            st.push(i);
        }
        return max_area;
    }

public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> heights(cols, 0);
        int max_rectangle = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Update heights based on current row element
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            // Compute the maximum rectangle for the current row's histogram
            max_rectangle = std::max(max_rectangle, largestRectangleArea(heights));
        }
        
        return max_rectangle;
    }
};
