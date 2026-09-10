#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // The width of the container is the distance between the two pointers
            int width = right - left;
            
            // The height of the water is limited by the shorter line
            int currentHeight = std::min(height[left], height[right]);
            
            // Update the maximum water found so far
            maxWater = std::max(maxWater, width * currentHeight);
            
            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};
