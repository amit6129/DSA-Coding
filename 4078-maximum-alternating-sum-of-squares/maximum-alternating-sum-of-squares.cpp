#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        
        // Convert all elements to their squares
        std::vector<long long> squares(n);
        for (int i = 0; i < n; ++i) {
            squares[i] = static_cast<long long>(nums[i]) * nums[i];
        }
        
        // Sort squares in ascending order
        std::sort(squares.begin(), squares.end());
        
        long long max_score = 0;
        int left = 0;         // Pointer for smallest elements (subtracted)
        int right = n - 1;    // Pointer for largest elements (added)
        
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                // Even index: add the largest available square
                max_score += squares[right--];
            } else {
                // Odd index: subtract the smallest available square
                max_score -= squares[left++];
            }
        }
        
        return max_score;
    }
};
