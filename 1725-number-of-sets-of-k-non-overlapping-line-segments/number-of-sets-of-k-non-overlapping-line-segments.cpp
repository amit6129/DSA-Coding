#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfSets(int n, int k) {
        int MOD = 1e9 + 7;
        int total_n = n + k - 1;
        int total_k = 2 * k;
        
        // If we don't have enough points to pick 2k coordinates
        if (total_k > total_n) return 0;
        
        // DP array to compute combinations space-optimized to O(k)
        std::vector<int> dp(total_k + 1, 0);
        dp[0] = 1; // C(i, 0) is always 1
        
        for (int i = 1; i <= total_n; ++i) {
            for (int j = std::min(i, total_k); j > 0; --j) {
                dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
        
        return dp[total_k];
    }
};
