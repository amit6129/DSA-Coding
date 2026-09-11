#include <vector>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        // Count the frequency of each digit in the input array
        int available_counts[10] = {0};
        for (int d : digits) {
            available_counts[d]++;
        }
        
        int valid_count = 0;
        
        // Loop through all possible 3-digit even numbers
        for (int num = 100; num < 1000; num += 2) {
            int hundreds = num / 100;
            int tens = (num / 10) % 10;
            int units = num % 10;
            
            // Count the frequencies needed for the current number
            int needed_counts[10] = {0};
            needed_counts[hundreds]++;
            needed_counts[tens]++;
            needed_counts[units]++;
            
            // Verify if we have enough digits to form this number
            bool is_possible = true;
            for (int i = 0; i < 10; ++i) {
                if (needed_counts[i] > available_counts[i]) {
                    is_possible = false;
                    break;
                }
            }
            
            if (is_possible) {
                valid_count++;
            }
        }
        
        return valid_count;
    }
};
