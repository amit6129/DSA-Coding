#include <vector>
#include <unordered_set>

class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        // Iterate through all possible starting positions
        for (int i = 0; i < n; ++i) {
            std::unordered_set<int> distinctElements;
            
            // Expand the subarray to the right
            for (int j = i; j < n; ++j) {
                distinctElements.insert(nums[j]);
                int distinctCount = distinctElements.size();
                
                // Add the square of the distinct count to the total sum
                totalSum += distinctCount * distinctCount;
            }
        }

        return totalSum;
    }
};
