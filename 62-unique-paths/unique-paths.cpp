#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Use a 1D DP array of size n initialized to 1
        std::vector<int> dp(n, 1);
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1]; // paths from top (dp[j]) + paths from left (dp[j-1])
            }
        }
        
        return dp[n - 1];
    }
};
