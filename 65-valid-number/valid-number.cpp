class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;
        
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            
            if (isdigit(c)) {
                seenDigit = true;
            } 
            else if (c == '+' || c == '-') {
                // Signs can only appear at the very start or right after an exponent 'e'/'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (c == 'e' || c == 'E') {
                // Exponent can only appear once and must follow at least one digit
                if (seenE || !seenDigit) {
                    return false;
                }
                seenE = true;
                seenDigit = false; // Reset to ensure an integer follows the exponent
            } 
            else if (c == '.') {
                // Dot can only appear once and cannot appear after an exponent
                if (seenDot || seenE) {
                    return false;
                }
                seenDot = true;
            } 
            else {
                // Any other character is invalid
                return false;
            }
        }
        
        return seenDigit;
    }
};
