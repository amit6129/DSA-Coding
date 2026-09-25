class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int total_water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                // If current left height is higher than left_max, update it
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    // Water trapped is the difference between left_max and current height
                    total_water += left_max - height[left];
                }
                ++left;
            } else {
                // If current right height is higher than right_max, update it
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    // Water trapped is the difference between right_max and current height
                    total_water += right_max - height[right];
                }
                --right;
            }
        }
        
        return total_water;
    }
};
