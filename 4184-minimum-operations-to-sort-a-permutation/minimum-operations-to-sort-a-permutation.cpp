#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        
        // Find the position of 0
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }

        // Check if the array is an increasing cyclic shift
        bool is_inc = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx + i) % n] != i) {
                is_inc = false;
                break;
            }
        }

        // Check if the array is a decreasing cyclic shift
        bool is_dec = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx - i + n) % n] != i) {
                is_dec = false;
                break;
            }
        }

        int min_ops = 1e9; // Initialize with a large value

        if (is_inc) {
            min_ops = std::min(min_ops, std::min(idx, n - idx + 2));
        }
        if (is_dec) {
            min_ops = std::min(min_ops, std::min(n - idx, idx + 2));
        }

        // If neither configuration is valid, it's impossible to sort
        return (min_ops == 1e9) ? -1 : min_ops;
    }
};
