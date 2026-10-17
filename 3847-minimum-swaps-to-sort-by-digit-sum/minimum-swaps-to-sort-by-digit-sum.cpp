#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    // Helper function to calculate the sum of digits of a number
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(std::vector<int>& nums) { // Function name fixed here
        int n = nums.size();
        
        // Pair structure: {value, original_index}
        std::vector<std::pair<int, int>> initialPos(n);
        for (int i = 0; i < n; ++i) {
            initialPos[i] = {nums[i], i};
        }
        
        // Precompute digit sums to avoid recalculating during sorting
        std::vector<int> digitSums(n);
        for (int i = 0; i < n; ++i) {
            digitSums[i] = getDigitSum(nums[i]);
        }
        
        // Sort based on the custom criteria
        std::sort(initialPos.begin(), initialPos.end(), [&](const auto& a, const auto& b) {
            int sumA = digitSums[a.second];
            int sumB = digitSums[b.second];
            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a.first < b.first;
        });
        
        // Track visited elements during cycle traversal
        std::vector<bool> visited(n, false);
        int totalSwaps = 0;
        
        for (int i = 0; i < n; ++i) {
            // If already visited or already in the correct position, skip
            if (visited[i] || initialPos[i].second == i) {
                continue;
            }
            
            // Calculate cycle size
            int cycleSize = 0;
            int current = i;
            
            while (!visited[current]) {
                visited[current] = true;
                // Move to the index where the current element originally came from
                current = initialPos[current].second;
                cycleSize++;
            }
            
            if (cycleSize > 1) {
                totalSwaps += (cycleSize - 1);
            }
        }
        
        return totalSwaps;
    }
};
