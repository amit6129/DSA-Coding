#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int k = 1; // Points to the next position to write a unique element
        
        for (int i = 1; i < nums.size(); ++i) {
            // If the current element is different from the last unique element found
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i]; // Move the unique element forward
                k++;               // Increment the unique count
            }
        }
        
        return k;
    }
};
