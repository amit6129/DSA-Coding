#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        
        // Find the absolute differences and determine the max difference
        std::vector<long long> bucket(100001, 0);
        int max_diff = 0;
        
        for (int i = 0; i < n; ++i) {
            int diff = std::abs(nums1[i] - nums2[i]);
            bucket[diff]++;
            max_diff = std::max(max_diff, diff);
        }
        
        // Greedily reduce the largest differences down
        for (int d = max_diff; d > 0; --d) {
            if (bucket[d] == 0) continue;
            
            if (k >= bucket[d]) {
                k -= bucket[d];
                bucket[d - 1] += bucket[d];
                bucket[d] = 0;
            } else {
                bucket[d - 1] += k;
                bucket[d] -= k;
                k = 0;
                break; // No more operations left
            }
        }
        
        // Calculate the final sum of squared differences
        long long min_squared_sum = 0;
        for (long long d = 1; d <= max_diff; ++d) {
            if (bucket[d] > 0) {
                min_squared_sum += (d * d) * bucket[d];
            }
        }
        
        return min_squared_sum;
    }
};
