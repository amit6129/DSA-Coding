#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        
        for (const std::string& s : strs) {
            std::string sorted_s = s;
            std::sort(sorted_s.begin(), sorted_s.end());
            map[sorted_s].push_back(s);
        }
        
        std::vector<std::vector<std::string>> result;
        for (auto& pair : map) {
            result.push_back(std::move(pair.second));
        }
        
        return result;
    }
};
