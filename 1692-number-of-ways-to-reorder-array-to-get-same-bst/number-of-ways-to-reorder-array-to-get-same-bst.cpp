#include <vector>

using namespace std;

class Solution {
    long long mod = 1e9 + 7;
    vector<vector<long long>> table;

    // Helper to calculate the number of ways for a sub-array
    long long dfs(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long leftWays = dfs(left) % mod;
        long long rightWays = dfs(right) % mod;

        // Combinations of (left.size() + right.size()) choose left.size()
        long long ways = table[n - 1][left.size()];
        ways = (ways * leftWays) % mod;
        ways = (ways * rightWays) % mod;

        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        // Precompute combinations using Pascal's triangle
        table.resize(n + 1, vector<long long>(n + 1, 1));
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }

        // Subtract 1 to exclude the original permutation
        return (dfs(nums) - 1 + mod) % mod;
    }
};
