#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0;
        for (const int num : nums) {
            // Allow the first two elements, or any element that differs 
            // from the element two positions back
            if (i < 2 || num > nums[i - 2]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};
