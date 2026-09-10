class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (except 0 itself) cannot be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            // Extract the last digit and add it to the reversed half
            reversedHalf = reversedHalf * 10 + (x % 10);
            // Remove the last digit from the original number
            x /= 10;
        }

        // For even-length numbers: x == reversedHalf
        // For odd-length numbers: x == reversedHalf / 10 (discards the middle digit)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
