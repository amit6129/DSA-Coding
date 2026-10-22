#include <vector>

class Solution {
public:
    int numTrees(int n) {
        // dp[i] will store the number of unique BSTs formed by i nodes
        std::vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; // An empty tree is 1 unique structural shape
        dp[1] = 1; // A tree with 1 node is 1 unique structural shape
        
        // Fill the DP table up to n
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                // j acts as the root node
                // Left subtree has (j - 1) nodes, Right subtree has (i - j) nodes
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};
