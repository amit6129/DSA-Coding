#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MAX_XOR = 1024; // Values up to 1023, fits within 10 bits

        // dp[j][k] stores whether an XOR value 'k' is reachable at column 'j'
        vector<vector<bool>> dp(n, vector<bool>(MAX_XOR, false));

        // Base case: Starting at (0, 0)
        dp[0][grid[0][0]] = true;

        // Populate the first row (can only move right)
        for (int j = 1; j < n; ++j) {
            int val = grid[0][j];
            for (int k = 0; k < MAX_XOR; ++k) {
                if (dp[j - 1][k]) {
                    dp[j][k ^ val] = true;
                }
            }
        }

        // Process remaining rows
        for (int i = 1; i < m; ++i) {
            vector<vector<bool>> next_dp(n, vector<bool>(MAX_XOR, false));

            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];

                // 1. Transition from the cell directly above (same column j, previous row)
                for (int k = 0; k < MAX_XOR; ++k) {
                    if (dp[j][k]) {
                        next_dp[j][k ^ val] = true;
                    }
                }

                // 2. Transition from the cell to the left (same row, previous column j-1)
                if (j > 0) {
                    for (int k = 0; k < MAX_XOR; ++k) {
                        if (next_dp[j - 1][k]) {
                            next_dp[j][k ^ val] = true;
                        }
                    }
                }
            }
            dp = std::move(next_dp); // Fixed unqualified std::move warning
        }

        // Look for the minimum achievable XOR value at the destination (m-1, n-1)
        for (int k = 0; k < MAX_XOR; ++k) {
            if (dp[n - 1][k]) {
                return k;
            }
        }

        return -1; 
    }
};
