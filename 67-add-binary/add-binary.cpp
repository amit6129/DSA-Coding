#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop until both strings are processed and no carry remains
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }

            // The bit to append is sum % 2
            result += std::to_string(sum % 2);

            // Calculate the new carry
            carry = sum / 2;
        }

        // The result is built backwards, so reverse it
        std::reverse(result.begin(), result.end());
        return result;
    }
};
