#include <string>

class Solution {
public:
    int minAddToMakeValid(std::string s) {
        int open_count = 0;
        int moves = 0;
        for (char c : s) {
            if (c == '(') {
                open_count++;
            } else {
                if (open_count > 0) {
                    open_count--;
                } else {
                    moves++;
                }
            }
        }
        return moves + open_count;
    }
};
