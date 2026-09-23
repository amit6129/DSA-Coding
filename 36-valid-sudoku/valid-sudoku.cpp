#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Use arrays of integers as bitmasks to track seen numbers (1-9)
        // rows[i], cols[j], and boxes[k] will store the bits representing numbers
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char val = board[r][c];
                
                // Skip empty cells
                if (val == '.') continue;
                
                // Convert char digit to a 0-indexed integer shift value (0 to 8)
                int mask = 1 << (val - '1');
                
                // Determine the index of the 3x3 sub-box (0 to 8)
                int box_idx = (r / 3) * 3 + (c / 3);
                
                // Check if the number has already been seen in this row, column, or box
                if ((rows[r] & mask) || (cols[c] & mask) || (boxes[box_idx] & mask)) {
                    return false;
                }
                
                // Mark the number as seen by setting its bit
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[box_idx] |= mask;
            }
        }
        
        return true;
    }
};
