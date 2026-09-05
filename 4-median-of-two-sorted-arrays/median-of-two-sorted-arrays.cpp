#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is always the shorter array to optimize binary search bounds
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        
        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            // If partition1 is 0, nothing is on the left side of nums1. Use INT_MIN
            // If partition1 is m, nothing is on the right side of nums1. Use INT_MAX
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            // Do the same boundary edge-case handling for nums2
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            // Correct partition achieved
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total elements combined is odd
                if ((m + n) % 2 == 1) {
                    return std::max(maxLeft1, maxLeft2);
                }
                // If total elements combined is even
                return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
            }
            // We are too far right in nums1; must move left
            else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            }
            // We are too far left in nums1; must move right
            else {
                low = partition1 + 1;
            }
        }
        
        return 0.0; // Fallback return for valid inputs
    }
};
