#include <vector>

class Solution {
public:
    int sumOfSquares(std::vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            // Check if the 1-based index (i + 1) divides n
            if (n % (i + 1) == 0) {
                total_sum += nums[i] * nums[i];
            }
        }
        
        return total_sum;
    }
};
