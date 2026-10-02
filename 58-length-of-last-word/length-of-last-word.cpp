#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int length = 0;
        int i = s.length() - 1;

        // 1. Skip any trailing spaces at the end of the string
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // 2. Count the characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
