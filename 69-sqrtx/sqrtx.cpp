class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int low = 1;
        int high = x;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Use long long to prevent overflow during squaring
            long long square = (long long)mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid; // Update the closest integer rounded down
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
