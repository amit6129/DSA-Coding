#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> st;
        std::stringstream ss(path);
        std::string token;
        
        // Split the path by '/'
        while (std::getline(ss, token, '/')) {
            // Skip empty tokens (caused by multiple slashes like '//') or '.' (current directory)
            if (token == "" || token == ".") {
                continue;
            }
            // Go up one level if we see '..'
            if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                // It's a valid directory name (including '...', '....', etc.)
                st.push_back(token);
            }
        }
        
        // Reconstruct the canonical path from the stack
        std::string result = "";
        for (const std::string& dir : st) {
            result += "/" + dir;
        }
        
        // If the stack was empty, return the root directory "/"
        return result.empty() ? "/" : result;
    }
};
