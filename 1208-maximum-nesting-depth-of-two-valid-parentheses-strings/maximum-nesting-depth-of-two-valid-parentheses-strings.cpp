#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        std::vector<int> ans;
        ans.reserve(seq.length());
        int d = 0;
        
        for (char c : seq) {
            if (c == '(') {
                d++;
                ans.push_back((d - 1) % 2);
            } else {
                ans.push_back((d - 1) % 2);
                d--;
            }
        }
        return ans;
    }
};
