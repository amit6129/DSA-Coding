#include <vector>

class Solution {
private:
    int rows, cols;

    // DFS to traverse and sink an island (turn land '0' into water '1')
    void dfs(std::vector<std::vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        // Mark as visited by turning it into water
        grid[r][c] = 1;
        
        // Traverse in all 4 directions
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int closedIsland(std::vector<std::vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int closedIslandsCount = 0;
        
        // Step 1: Flood-fill all land connected to the boundary
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Check if it's a boundary cell and is land
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(grid, r, c);
                }
            }
        }
        
        // Step 2: Count the remaining isolated/closed islands
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    closedIslandsCount++;
                    dfs(grid, r, c); // Sink this island
                }
            }
        }
        
        return closedIslandsCount;
    }
};
