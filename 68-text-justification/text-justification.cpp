#include <vector>
#include <string>

class Solution {
public:
    std::vector<string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> res;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLen = 0;

            // Find words that fit in current line
            while (j < n && lineLen + words[j].length() + (j - i) <= maxWidth) {
                lineLen += words[j].length();
                j++;
            }

            std::string line = "";
            int numWords = j - i;
            int numSpaces = maxWidth - lineLen;

            // Last line or single word: left-justified
            if (j == n || numWords == 1) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += std::string(maxWidth - line.length(), ' ');
            } 
            // Fully justified line
            else {
                int spacesBetween = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);

                for (int k = i; k < j - 1; ++k) {
                    line += words[k];
                    line += std::string(spacesBetween + (k - i < extraSpaces ? 1 : 0), ' ');
                }
                line += words[j - 1]; // Last word in line has no trailing spaces after it
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};
