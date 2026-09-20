#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow cases immediately
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        // Determine the sign of the quotient
        // A true value means the result will be negative
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to negative values to prevent overflow with INT_MIN.
        // In 32-bit signed integers, |INT_MIN| > INT_MAX, so moving to negative space is safe.
        long long absDividend = std::abs((long long)dividend);
        long long absDivisor = std::abs((long long)divisor);

        long long quotient = 0;

        // Use bitwise shifting to subtract multiples of the divisor efficiently
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            // Shift the divisor left until doubling it exceeds the remaining dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // Deduct the largest shifted divisor from the dividend and add to quotient
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        // Apply the correct sign and cast down to standard 32-bit int
        return isNegative ? -quotient : quotient;
    }
};
