#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int divisibleIslandsCount = 0;

        // Directions array for 4-directional traversal
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Found an unvisited piece of land
                if (grid[r][c] > 0) {
                    long long islandSum = 0;
                    queue<pair<int, int>> q;

                    // Push start cell and mark as visited (0) immediately
                    q.push({r, c});
                    islandSum += grid[r][c];
                    grid[r][c] = 0;

                    // Iterative BFS to sum up the island values safely
                    while (!q.empty()) {
                        auto [currR, currC] = q.front();
                        q.pop();

                        for (int i = 0; i < 4; ++i) {
                            int nextR = currR + dRow[i];
                            int nextC = currC + dCol[i];

                            // Check boundaries and if it's an unvisited positive integer
                            if (nextR >= 0 && nextR < rows && nextC >= 0 && nextC < cols && grid[nextR][nextC] > 0) {
                                islandSum += grid[nextR][nextC];
                                grid[nextR][nextC] = 0; // Mark visited
                                q.push({nextR, nextC});
                            }
                        }
                    }

                    // Check if the total island value is divisible by k
                    if (islandSum % k == 0) {
                        divisibleIslandsCount++;
                    }
                }
            }
        }

        return divisibleIslandsCount;
    }
};
