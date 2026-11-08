#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;
        
        for (int i = 0; i < numRows; ++i) {
            // Create a row with (i + 1) elements, all initialized to 1
            std::vector<int> row(i + 1, 1);
            
            // Fill in the inner elements of the row
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            // Add the completed row to the triangle
            triangle.push_back(row);
        }
        
        return triangle;
    }
};
