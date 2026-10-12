#include <vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        // Since nums[i] <= 10^9, 30 bits are sufficient (2^29 < 10^9 < 2^30)
        std::vector<int> bitCount(30, 0);
        
        // Step 1: Count the occurrences of each bit across all numbers
        for (int num : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        
        long long max_sum_squares = 0;
        
        // Step 2: Greedily construct the k largest numbers
        for (int step = 0; step < k; ++step) {
            long long current_num = 0;
            for (int i = 0; i < 30; ++i) {
                // If this bit is still available, assign it to the current large number
                if (bitCount[i] > 0) {
                    current_num |= (1LL << i);
                    bitCount[i]--;
                }
            }
            // Add the square of the constructed number to our total modulo 10^9 + 7
            max_sum_squares = (max_sum_squares + (current_num * current_num) % MOD) % MOD;
        }
        
        return max_sum_squares;
    }
};
