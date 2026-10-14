#include <string>

class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        // If the required sum exceeds the maximum possible sum for 'num' digits
        if (sum > 9 * num) {
            return "";
        }
        
        int n9 = sum / 9;
        int rem = sum % 9;
        int n0 = num - n9 - (rem > 0 ? 1 : 0);
        
        std::string result = "";
        result.reserve(num); // Optimize memory allocation
        
        // Greedily append the largest digits first
        result.append(n9, '9');
        if (rem > 0) {
            result.push_back('0' + rem);
        }
        result.append(n0, '0');
        
        return result;
    }
};
