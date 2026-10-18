#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> res;

    void backtrack(const string& s, int start, vector<string>& path) {
        if (path.size() == 4) {
            if (start == s.length()) {
                res.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            }
            return;
        }

        int remaining_chars = s.length() - start;
        int remaining_segments = 4 - path.size();
        if (remaining_chars < remaining_segments || remaining_chars > remaining_segments * 3) {
            return;
        }

        for (int length = 1; length <= 3; ++length) {
            if (start + length > s.length()) break;

            string segment = s.substr(start, length);

            // Leading zero check
            if (segment.length() > 1 && segment[0] == '0') continue;

            // Value constraint check
            if (stoi(segment) <= 255) {
                path.push_back(segment);
                backtrack(s, start + length, path);
                path.pop_back(); // Backtrack
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12) return {};
        vector<string> path;
        backtrack(s, 0, path);
        return res;
    }
};
