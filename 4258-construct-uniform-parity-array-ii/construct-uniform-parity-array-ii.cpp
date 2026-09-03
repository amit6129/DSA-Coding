#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        int min_even = INT_MAX;
        
        // Find the minimum odd and even elements in a single pass
        for (int num : nums1) {
            if (num % 2 != 0) {
                min_odd = min(min_odd, num);
            } else {
                min_even = min(min_even, num);
            }
        }
        
        // Scenario 1: No odd numbers exist. The array is already all even.
        if (min_odd == INT_MAX) {
            return true;
        }
        
        // Scenario 2: Odd numbers exist. We can only make the array uniform 
        // if the smallest odd number can be used to flip all even numbers.
        return min_odd < min_even;
    }
};

