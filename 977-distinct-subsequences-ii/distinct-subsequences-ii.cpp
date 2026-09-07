class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        
        // Stores the number of subsequences ending with each of the 26 lowercase letters
        vector<long> last(26, 0);
        long current_total = 0;
        
        for (char c : s) {
            int idx = c - 'a';
            
            // New subsequences formed by appending 'c' to all existing ones + 'c' itself
            long new_added = (current_total + 1) % MOD;
            
            // Calculate next total: total + new_added - previous_contributions_of_c
            long next_total = (current_total + new_added - last[idx]) % MOD;
            
            // Handle negative results due to modulo subtraction in C++
            if (next_total < 0) {
                next_total += MOD;
            }
            
            current_total = next_total;
            last[idx] = new_added; // Update the contribution of this character
        }
        
        return current_total;
    }
};
