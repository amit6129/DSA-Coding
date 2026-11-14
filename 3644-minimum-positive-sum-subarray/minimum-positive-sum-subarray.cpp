#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;
        bool found = false;

        // Iterate over every possible starting index
        for (int i = 0; i < n; ++i) {
            int currentSum = 0;
            
            // Expand the subarray from index i to j
            for (int j = i; j < n; ++j) {
                currentSum += nums[j];
                int length = j - i + 1;
                
                // Stop expanding if the subarray exceeds maximum allowed length r
                if (length > r) {
                    break;
                }
                
                // Check if length is within [l, r] and sum is strictly positive
                if (length >= l && currentSum > 0) {
                    minSum = min(minSum, currentSum);
                    found = true;
                }
            }
        }

        return found ? minSum : -1;
    }
};
