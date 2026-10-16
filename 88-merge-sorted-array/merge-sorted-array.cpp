#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int p1 = m - 1;     // Pointer for valid elements in nums1
        int p2 = n - 1;     // Pointer for nums2
        int p = m + n - 1;  // Pointer for the insertion position at the end of nums1

        // Merge from right to left
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        // If there are leftover elements in nums2, copy them over.
        // Leftover elements in nums1 are already sorted and in place.
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};
