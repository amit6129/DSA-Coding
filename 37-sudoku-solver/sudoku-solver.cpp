#include <vector>

class Solution {
private:
    // Bitmasks to track used digits (1-9) for each row, column, and 3x3 box
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};

    // Helper to get the box index from row and column
    inline int getBoxIndex(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    bool backtrack(std::vector<std::vector<char>>& board, int cellIdx) {
        // Base case: If we successfully placed numbers in all 81 cells, the board is solved
        if (cellIdx == 81) return true;

        int r = cellIdx / 9;
        int c = cellIdx % 9;

        // If the cell is already filled, skip to the next cell
        if (board[r][c] != '.') {
            return backtrack(board, cellIdx + 1);
        }

        int boxIdx = getBoxIndex(r, c);

        // Try placing digits from 1 to 9
        for (int num = 1; num <= 9; ++num) {
            int mask = 1 << (num - 1);

            // Check if 'num' is already used in this row, col, or box
            if (!(rows[r] & mask) && !(cols[c] & mask) && !(boxes[boxIdx] & mask)) {
                
                // Place the digit (Choose)
                board[r][c] = '0' + num;
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIdx] |= mask;

                // Move to the next cell (Explore)
                if (backtrack(board, cellIdx + 1)) {
                    return true;
                }

                // Remove the digit (Backtrack / Undo Choose)
                board[r][c] = '.';
                rows[r] &= ~mask;
                cols[c] &= ~mask;
                boxes[boxIdx] &= ~mask;
            }
        }

        return false; // Trigger backtracking if no digit fits
    }

public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        // Step 1: Initialize bitmasks with the numbers already present on the board
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '0';
                    int mask = 1 << (num - 1);
                    int boxIdx = getBoxIndex(r, c);
                    
                    rows[r] |= mask;
                    cols[c] |= mask;
                    boxes[boxIdx] |= mask;
                }
            }
        }

        // Step 2: Start backtracking from the top-left cell (index 0)
        backtrack(board, 0);
    }
};
