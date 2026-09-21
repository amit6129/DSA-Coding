#include <vector>

class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> ans(k, 0);
        std::vector<long long> cnt(k, 0);
        
        for (int x : nums) {
            int val = x % k;
            std::vector<long long> next_cnt(k, 0);
            
            // Subarray starting at the current element
            next_cnt[val] += 1;
            
            // Extending existing subarrays ending at the previous element
            for (int rem = 0; rem < k; ++rem) {
                if (cnt[rem] > 0) {
                    next_cnt[(rem * val) % k] += cnt[rem];
                }
            }
            
            cnt = std::move(next_cnt);
            
            // Accumulate the counts for the current end position
            for (int rem = 0; rem < k; ++rem) {
                ans[rem] += cnt[rem];
            }
        }
        
        return ans;
    }
};
