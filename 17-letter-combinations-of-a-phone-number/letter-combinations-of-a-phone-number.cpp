#include <vector>
#include <string>

class Solution {
private:
    // Phone keypad mapping where the index corresponds to the digit character
    const std::vector<std::string> keypad = {
        "",     "",     "abc",  "def", 
        "ghi",  "jkl",  "mno",  "pqrs", 
        "tuv",  "wxyz"
    };

    void backtrack(const std::string& digits, int index, std::string& current, std::vector<std::string>& result) {
        // Base case: if the current combination is complete
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the letters that the current digit maps to
        std::string letters = keypad[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);             // Choose
            backtrack(digits, index + 1, current, result); // Explore
            current.pop_back();                  // Unchoose (Backtrack)
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }

        std::string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};
