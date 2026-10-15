#include <string>
#include <unordered_map>
#include <vector>

class Solution {
private:
    // Hash map to store results of subproblems: "s1_s2" -> true/false
    std::unordered_map<std::string, bool> memo;

public:
    bool isScramble(std::string s1, std::string s2) {
        // Base Cases
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        // Check if this pair of strings has already been solved
        std::string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.length();
        
        // Pruning: If the frequency of characters doesn't match, they can't be scrambled
        std::vector<int> count(26, 0);
        for (int i = 0; i < n; ++i) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                return memo[key] = false;
            }
        }

        // Try splitting the string at every possible index `i`
        for (int i = 1; i < n; ++i) {
            // Case 1: The substrings were NOT swapped
            bool noSwap = isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                           isScramble(s1.substr(i), s2.substr(i));
            
            // Case 2: The substrings WERE swapped
            bool swap = isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                        isScramble(s1.substr(i), s2.substr(0, n - i));

            if (noSwap || swap) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};
