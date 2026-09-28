#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        // Use a long long variable to handle the overflow case when n = -2^31
        long long N = n;
        
        // If the exponent is negative, invert the base and make the exponent positive
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        
        double result = 1.0;
        double current_product = x;
        
        // Binary exponentiation loop
        while (N > 0) {
            // If the current exponent bit is odd, multiply the result by current product
            if (N % 2 == 1) {
                result *= current_product;
            }
            // Square the base for the next power of 2
            current_product *= current_product;
            // Divide the exponent by 2
            N /= 2;
        }
        
        return result;
    }
};
