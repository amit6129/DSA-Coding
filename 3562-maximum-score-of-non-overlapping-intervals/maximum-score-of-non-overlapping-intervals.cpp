#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
        bool operator<(const Interval& other) const {
            return l < other.l;
        }
    };

    struct DPState {
        long long weight = 0;
        vector<int> indices;
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> sorted_intervals(n);
        for (int i = 0; i < n; ++i) {
            sorted_intervals[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        // Sort intervals by start time
        sort(sorted_intervals.begin(), sorted_intervals.end());
        
        // memo[i][quota]
        vector<vector<DPState>> memo(n + 1, vector<DPState>(5));
        vector<vector<bool>> visited(n + 1, vector<bool>(5, false));

        auto solve = [&](auto& self, int i, int quota) -> DPState {
            if (i == n || quota == 0) return {0, {}};
            if (visited[i][quota]) return memo[i][quota];

            // Choice 1: Skip
            DPState skip = self(self, i + 1, quota);

            // Choice 2: Pick
            // Find the next non-overlapping interval using binary search
            int low = i + 1, high = n, next_idx = n;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (mid < n && sorted_intervals[mid].l > sorted_intervals[i].r) {
                    next_idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            DPState pick = self(self, next_idx, quota - 1);
            pick.weight += sorted_intervals[i].weight;
            pick.indices.push_back(sorted_intervals[i].id);
            sort(pick.indices.begin(), pick.indices.end());

            DPState best;
            if (pick.weight > skip.weight) {
                best = pick;
            } else if (skip.weight > pick.weight) {
                best = skip;
            } else {
                best = (pick.indices < skip.indices) ? pick : skip;
            }

            visited[i][quota] = true;
            return memo[i][quota] = best;
        };

        return solve(solve, 0, 4).indices;
    }
};
