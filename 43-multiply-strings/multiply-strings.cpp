#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        // Handle the edge case where either number is zero
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size();
        int n = num2.size();
        // The maximum possible length of the product is m + n
        std::vector<int> result(m + n, 0);
        
        // Loop backwards from the rightmost digits
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Multiply the individual digits
                int mul = (num1[i] - '0') * (num2[j] - '0');
                
                // Determine the positions in the result array
                int p1 = i + j;     // Carry position
                int p2 = i + j + 1; // Current digit position
                
                // Add multiplication result to the current position
                int sum = mul + result[p2];
                
                // Store the unit digit at p2 and carry forward to p1
                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }
        
        // Convert the result vector to a string
        std::string product = "";
        for (int digit : result) {
            // Skip leading zeros
            if (!(product.empty() && digit == 0)) {
                product += std::to_string(digit);
            }
        }
        
        return product;
    }
};
