#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> st;
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; ++i) {
            // Use 0 as a dummy height at index 'n' to flush out remaining items in the stack
            int current_height = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && heights[st.top()] > current_height) {
                int height = heights[st.top()];
                st.pop();
                
                // Calculate width of the rectangle
                int width = st.empty() ? i : (i - st.top() - 1);
                
                max_area = std::max(max_area, height * width);
            }
            st.push(i);
        }
        
        return max_area;
    }
};
