class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int prev2 = 1; // Ways to reach 1 step below
        int prev1 = 2; // Ways to reach 2 steps below
        int current = 0;
        
        for (int i = 3; i <= n; ++i) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return current;
    }
};
