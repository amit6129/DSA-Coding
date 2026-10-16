#include <vector>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        // Total number of elements in an n-bit gray code sequence is 2^n
        int num_elements = 1 << n;
        std::vector<int> result;
        result.reserve(num_elements);
        
        // Generate the sequence directly using the binary-to-gray formula
        for (int i = 0; i < num_elements; ++i) {
            result.push_back(i ^ (i >> 1));
        }
        
        return result;
    }
};
