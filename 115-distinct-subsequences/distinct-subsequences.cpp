#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Base case optimization: if s is shorter than t, it's impossible to form t
        if (m < n) return 0;
        
        // Use a 1D vector of size n + 1 to optimize space.
        // Using 'unsigned long long' to safely handle intermediate overflows.
        vector<unsigned long long> dp(n + 1, 0);
        
        // Base Case: An empty string t can always be matched in exactly 1 way
        dp[0] = 1;
        
        // Iterate through each character of string s
        for (int i = 1; i <= m; i++) {
            // Traverse backwards to prevent using the updated values from the current row
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
                // If s[i-1] != t[j-1], dp[j] remains unchanged (equivalent to dp[i][j] = dp[i-1][j])
            }
        }
        
        return (int)dp[n];
    }
};

