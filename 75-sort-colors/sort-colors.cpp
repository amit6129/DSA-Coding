#include <vector>
#include <utility>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap with low pointer, increment both low and mid
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                // 1 is in the correct place, just move mid forward
                mid++;
            } 
            else { // nums[mid] == 2
                // Swap with high pointer, decrement high
                // Do NOT increment mid yet because the swapped element needs to be checked
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
