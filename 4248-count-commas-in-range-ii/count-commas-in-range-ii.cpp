class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;
        long long factor = 1000;
        
        // Loop through each comma threshold (1,000, 1,000,000, etc.)
        while (factor <= n) {
            total_commas += (n - factor + 1);
            
            // Prevent potential overflow if factor * 1000 exceeds LLONG_MAX
            if (factor > LLONG_MAX / 1000) {
                break;
            }
            factor *= 1000;
        }
        
        return total_commas;
    }
};
