#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.length();
        // dp[i] stores the number of ways to decode the substring s[0...i-1]
        std::vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; // An empty string has 1 valid way to decode
        dp[1] = 1; // A single non-zero digit has 1 valid way to decode
        
        for (int i = 2; i <= n; ++i) {
            // Check if the single digit s[i-1] is valid (1-9)
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            
            // Check if the two-digit number s[i-2...i-1] is valid (10-26)
            int twoDigit = std::stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};
