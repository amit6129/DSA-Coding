#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> createGrid(int m, int n) {
        // Initialize an m x n grid filled with '#'
        std::vector<std::string> grid(m, std::string(n, '#'));
        
        // Create an L-shaped path: go right across row 0, then down column n-1
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};
