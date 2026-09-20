#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        // Build frequency map for the target words
        std::unordered_map<std::string, int> wordFreq;
        for (const std::string& word : words) {
            wordFreq[word]++;
        }

        // Run the sliding window shifted by every possible remainder index up to wordLen
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            int count = 0;
            std::unordered_map<std::string, int> currentFreq;

            // Expand the window to the right by one word length at a time
            while (right + wordLen <= sLen) {
                std::string word = s.substr(right, wordLen);
                right += wordLen;

                // Case 1: The extracted word belongs to our valid words list
                if (wordFreq.count(word)) {
                    currentFreq[word]++;
                    count++;

                    // If a word's count exceeds its target limit, shrink window from the left
                    while (currentFreq[word] > wordFreq[word]) {
                        std::string leftWord = s.substr(left, wordLen);
                        currentFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // If the window size perfectly matches the total concatenated length
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } 
                // Case 2: The word is completely invalid; reset the window
                else {
                    currentFreq.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
