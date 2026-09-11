#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        // Map each Roman symbol to its corresponding integer value
        std::unordered_map<char, int> roman_map = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            // If the current value is less than the next value, subtract it
            if (i < n - 1 && roman_map[s[i]] < roman_map[s[i + 1]]) {
                total -= roman_map[s[i]];
            } 
            // Otherwise, add it
            else {
                total += roman_map[s[i]];
            }
        }
        
        return total;
    }
};
