#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int n = s1.length();
        int m = s2.length();
        
        // If total length doesn't match, s3 cannot be formed
        if (n + m != s3.length()) {
            return false;
        }
        
        // dp[i][j] represents if s3[0...i+j-1] is formed by s1[0...i-1] and s2[0...j-1]
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    // Only s2 is being consumed
                    dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);
                } else if (j == 0) {
                    // Only s1 is being consumed
                    dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
                } else {
                    // Pull from either taking from s1 or taking from s2
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || 
                               (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};
