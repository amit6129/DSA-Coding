#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals based on their start times
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;
        
        // Start with the first interval
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // Get the last merged interval to compare with the current one
            auto& last_merged = merged.back();
            
            // If the current interval overlaps with the last merged interval
            if (intervals[i][0] <= last_merged[1]) {
                // Merge them by updating the end time to the maximum of both
                last_merged[1] = std::max(last_merged[1], intervals[i][1]);
            } else {
                // No overlap, so just add the current interval to the list
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
