#include <vector>
#include <algorithm>

class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();
        std::vector<std::pair<int, int>> points1, points2;
        
        // Gather the coordinates of all '1's in both images
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) points1.push_back({r, c});
                if (img2[r][c] == 1) points2.push_back({r, c});
            }
        }
        
        // Count frequencies of each translation vector (dr, dc)
        // Since dr and dc range from -(n-1) to (n-1), we offset by n to use a 2D array
        std::vector<std::vector<int>> shiftCount(2 * n, std::vector<int>(2 * n, 0));
        int maxOverlap = 0;
        
        for (const auto& p1 : points1) {
            for (const auto& p2 : points2) {
                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;
                
                shiftCount[dr + n][dc + n]++;
                maxOverlap = std::max(maxOverlap, shiftCount[dr + n][dc + n]);
            }
        }
        
        return maxOverlap;
    }
};
