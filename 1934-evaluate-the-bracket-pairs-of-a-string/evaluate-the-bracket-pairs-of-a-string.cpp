#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string evaluate(std::string s, std::vector<std::vector<std::string>>& knowledge) {
        // Build the hash map for O(1) average lookup time
        std::unordered_map<std::string, std::string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        std::string result = "";
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            if (s[i] == '(') {
                // Find the closing bracket
                int j = i + 1;
                while (j < n && s[j] != ')') {
                    j++;
                }
                
                // Extract the key using substring
                std::string key = s.substr(i + 1, j - i - 1);
                
                // Look up the key in the map
                auto it = dict.find(key);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
                
                // Move index past the closing bracket
                i = j + 1;
            } else {
                result += s[i];
                i++;
            }
        }
        
        return result;
    }
};
