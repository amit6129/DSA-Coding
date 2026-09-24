#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        // Base case
        if (n == 1) return "1";
        
        // Recursively find the (n-1)th sequence
        std::string prev = countAndSay(n - 1);
        std::string result = "";
        
        int length = prev.length();
        int count = 1;
        
        // Perform Run-Length Encoding (RLE)
        for (int i = 0; i < length; ++i) {
            // If the next character is the same, increment the count
            if (i + 1 < length && prev[i] == prev[i + 1]) {
                count++;
            } else {
                // Append the count and the character to the result
                result += std::to_string(count) + prev[i];
                count = 1; // Reset count for the next group
            }
        }
        
        return result;
    }
};
