class Solution {
private:
    int count = 0;
    
    void solve(int row, int n, int cols, int diag1, int diag2) {
        if (row == n) {
            count++;
            return;
        }
        
        int available = ((1 << n) - 1) & (~(cols | diag1 | diag2));
        while (available) {
            int p = available & -available; // Get lowest set bit
            available -= p;
            solve(row + 1, n, cols | p, (diag1 | p) << 1, (diag2 | p) >> 1);
        }
    }

public:
    int totalNQueens(int n) {
        count = 0;
        solve(0, n, 0, 0, 0);
        return count;
    }
};
