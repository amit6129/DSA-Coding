#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;
    vector<long long> sum_sq;
    vector<long long> sum_val;
    vector<long long> lazy;

    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;
        
        int mid = start + (end - start) / 2;
        int left = 2 * node;
        int right = 2 * node + 1;
        long long val = lazy[node];

        // Update left child
        long long len_l = mid - start + 1;
        sum_sq[left] = (sum_sq[left] + 2 * val * sum_val[left] + val * val % MOD * len_l) % MOD;
        sum_val[left] = (sum_val[left] + val * len_l) % MOD;
        lazy[left] = (lazy[left] + val) % MOD;

        // Update right child
        long long len_r = end - mid;
        sum_sq[right] = (sum_sq[right] + 2 * val * sum_val[right] + val * val % MOD * len_r) % MOD;
        sum_val[right] = (sum_val[right] + val * len_r) % MOD;
        lazy[right] = (lazy[right] + val) % MOD;

        lazy[node] = 0;
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            long long len = end - start + 1;
            sum_sq[node] = (sum_sq[node] + 2 * val * sum_val[node] + val * val % MOD * len) % MOD;
            sum_val[node] = (sum_val[node] + val * len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }
        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        sum_sq[node] = (sum_sq[2 * node] + sum_sq[2 * node + 1]) % MOD;
        sum_val[node] = (sum_val[2 * node] + sum_val[2 * node + 1]) % MOD;
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return sum_sq[node];
        push(node, start, end);
        int mid = start + (end - start) / 2;
        return (query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r)) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum_sq.assign(4 * n, 0);
        sum_val.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_pos;
        long long total_sum = 0;

        for (int j = 0; j < n; ++j) {
            int last_idx = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;
            
            // Add 1 to all distinct counters D[i] for i from last_idx + 1 to j
            update(1, 0, n - 1, last_idx + 1, j, 1);
            
            // Accumulate the current sum of squares for all subarrays ending at j
            total_sum = (total_sum + query(1, 0, n - 1, 0, j)) % MOD;
            
            last_pos[nums[j]] = j;
        }

        return (total_sum + MOD) % MOD;
    }
};
