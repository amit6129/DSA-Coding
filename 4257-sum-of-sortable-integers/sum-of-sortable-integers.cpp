#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        // Create the globally sorted version of the array
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        // Find all divisors of n
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }
        
        long long ans = 0;
        
        // Check each divisor k
        for (int k : divisors) {
            bool possible = true;
            
            for (int i = 0; i < n; i += k) {
                int drop_idx = -1;
                int drop_count = 0;
                
                // Count the number of drops in the current block of nums
                for (int j = 0; j < k - 1; ++j) {
                    if (nums[i + j] > nums[i + j + 1]) {
                        drop_count++;
                        drop_idx = j;
                    }
                }
                
                // If there is more than 1 drop, it's impossible to sort by rotation
                if (drop_count > 1) {
                    possible = false;
                    break;
                }
                
                // Verify if the rotated block matches the sorted_nums block
                if (drop_count == 0) {
                    // Block has 0 drops, must match sorted block directly
                    for (int j = 0; j < k; ++j) {
                        if (nums[i + j] != sorted_nums[i + j]) {
                            possible = false;
                            break;
                        }
                    }
                } else {
                    // Block has 1 drop at drop_idx. 
                    // The elements after the drop come first, followed by elements before/at the drop.
                    int s_idx = 0;
                    // Elements after the drop: from drop_idx + 1 to k - 1
                    for (int j = drop_idx + 1; j < k; ++j) {
                        if (nums[i + j] != sorted_nums[i + s_idx]) {
                            possible = false;
                            break;
                        }
                        s_idx++;
                    }
                    // Elements before/at the drop: from 0 to drop_idx
                    for (int j = 0; j <= drop_idx; ++j) {
                        if (!possible || nums[i + j] != sorted_nums[i + s_idx]) {
                            possible = false;
                            break;
                        }
                        s_idx++;
                    }
                }
                
                if (!possible) break;
            }
            
            if (possible) {
                ans += k;
            }
        }
        
        return ans;
    }
};
