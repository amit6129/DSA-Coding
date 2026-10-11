#include <vector>
#include <string>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size(); // Corrected to board[0].size()
        
        // Scan the board to find the starting letter
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int r, int c, int index) {
        // Base Case: If we matched all characters, the word is found
        if (index == word.length()) {
            return true;
        }
        
        // Correctly check rows (board.size) and columns (board[0].size)
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }
        
        // Save current character and mark cell as visited
        char temp = board[r][c];
        board[r][c] = '#'; 
        
        // Explore all 4 adjacent directions: down, up, right, left
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);
        
        // Backtrack: Restore the original character
        board[r][c] = temp;
        
        return found;
    }
};
