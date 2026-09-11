#include <string>
#include <vector>

class Solution {
public:
    string intToRoman(int num) {
        // Define values and their corresponding Roman symbols from highest to lowest
        const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const std::string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        std::string result = "";
        
        // Loop through each value-symbol pair
        for (int i = 0; i < 13; ++i) {
            // Repeat the symbol while the number is greater than or equal to the current value
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        
        return result;
    }
};
