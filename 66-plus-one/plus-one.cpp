#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the digits from the rightmost (least significant) to leftmost
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // No further carry, we are done
            }
            // If the digit is 9, it becomes 0 and carry moves left
            digits[i] = 0;
        }
        
        // If all digits were 9 (e.g., 999 -> 1000), insert a 1 at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
