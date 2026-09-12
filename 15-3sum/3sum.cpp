#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ++i) {
            // Since the array is sorted, if nums[i] is greater than 0,
            // no three numbers can sum to 0.
            if (nums[i] > 0) break;
            
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                
                if (total == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second and third elements
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (total < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};
