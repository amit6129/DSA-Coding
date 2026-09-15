#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            // Push open brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // Handle closing brackets
            else {
                // If stack is empty, there's no matching opening bracket
                if (st.empty()) return false;
                
                char top = st.top();
                // Check if the current closing bracket matches the last opening bracket
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false; // Mismatched types
                }
            }
        }
        
        // If the stack is empty, all brackets were successfully matched
        return st.empty();
    }
};
