#include <string>
#include <vector>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        // 1. Precompute factorials up to (n-1) and store available numbers
        std::vector<int> factorials(n, 1);
        std::vector<int> numbers;
        
        for (int i = 1; i < n; ++i) {
            factorials[i] = factorials[i - 1] * i;
        }
        
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }
        
        // Convert k to 0-indexed
        k--;
        
        std::string result = "";
        
        // 2. Determine digits one by one
        for (int i = n - 1; i >= 0; --i) {
            // Find the index of the number to place next
            int index = k / factorials[i];
            
            // Append the chosen number to the result string
            result += std::to_string(numbers[index]);
            
            // Remove the used number from the available collection
            numbers.erase(numbers.begin() + index);
            
            // Update k for the remaining digits
            k %= factorials[i];
        }
        
        return result;
    }
};
