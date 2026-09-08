#include <algorithm>

class Solution {
public:
    int countCommas(int n) {
        // Numbers from 1 to 999 use 0 commas.
        // Numbers from 1000 onwards use exactly 1 comma.
        return std::max(0, n - 999);
    }
};

