class Solution {
public:
    int countCommas(int n) {
        // If n is less than 1000, 0 is returned.
        // Otherwise, it counts every number from 1000 to n.
        return std::max(0, n - 999);
    }
};
