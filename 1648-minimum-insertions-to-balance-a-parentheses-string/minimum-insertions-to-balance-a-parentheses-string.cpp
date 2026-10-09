#include <string>

class Solution {
public:
    int minInsertions(std::string s) {
        int insertions = 0;
        int needed_rights = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                // If we need an odd number of right parentheses, it means we have a single ')' 
                // waiting for its pair. We must close it by inserting a ')' right now.
                if (needed_rights % 2 != 0) {
                    insertions++;      // Insert a ')'
                    needed_rights--;   // It's balanced out now
                }
                needed_rights += 2;    // Every '(' requires two ')'
            } 
            else { // s[i] == ')'
                // Check if the next character forms a pair '))'
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; // Consume the next ')' as part of the pair
                } else {
                    insertions++; // Missing a closing ')', so insert one to make a pair
                }
                
                // Now we have a complete pair '))'. Let's match it with an opening '('
                if (needed_rights >= 2) {
                    needed_rights -= 2; // Match with an existing '('
                } else {
                    insertions++; // No '(' available, so we must insert one '('
                }
            }
        }
        
        // Any remaining needed right parentheses at the end must be added
        return insertions + needed_rights;
    }
};
