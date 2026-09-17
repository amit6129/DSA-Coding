#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        // min_len[i] will store the minimum length of a valid subarray found in arr[0...i]
        std::vector<int> min_len(n, INT_MAX);
        
        int left = 0;
        int current_sum = 0;
        int min_total_length = INT_MAX;
        int current_min_len = INT_MAX;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            // Shrink window from the left if the sum exceeds target
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }

            // Found a valid subarray matching the target
            if (current_sum == target) {
                int len = right - left + 1;

                // Check if a valid non-overlapping subarray exists to the left of our window
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    min_total_length = std::min(min_total_length, min_len[left - 1] + len);
                }

                // Update the best minimum length seen so far up to this point
                current_min_len = std::min(current_min_len, len);
            }

            // Store the best result for the current prefix index
            min_len[right] = current_min_len;
        }

        return min_total_length == INT_MAX ? -1 : min_total_length;
    }
};
