#include <vector>
#include <string>

class Solution {
private:
    std::vector<std::vector<std::string>> solutions;
    std::vector<bool> cols;
    std::vector<bool> posDiag; // row + col
    std::vector<bool> negDiag; // row - col

    void backtrack(int row, int n, std::vector<std::string>& board) {
        // Base case: If we've successfully placed queens in all rows
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            // Check if placing a queen here is invalid
            if (cols[col] || posDiag[row + col] || negDiag[row - col + n]) {
                continue;
            }

            // Place the queen
            board[row][col] = 'Q';
            cols[col] = true;
            posDiag[row + col] = true;
            negDiag[row - col + n] = true;

            // Move to the next row
            backtrack(row + 1, n, board);

            // Backtrack (remove the queen)
            board[row][col] = '.';
            cols[col] = false;
            posDiag[row + col] = false;
            negDiag[row - col + n] = false;
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        solutions.clear();
        
        // Initialize tracking arrays
        cols.assign(n, false);
        posDiag.assign(2 * n, false);
        negDiag.assign(2 * n, false);

        // Create an empty board configuration
        std::vector<std::string> board(n, std::string(n, '.'));

        // Start backtracking from the 0th row
        backtrack(0, n, board);

        return solutions;
    }
};
