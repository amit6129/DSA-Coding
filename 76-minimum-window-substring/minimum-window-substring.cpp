class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequencies needed from t (ASCII size 128 covers all English letters)
        vector<int> target_counts(128, 0);
        for (char c : t) {
            target_counts[c]++;
        }

        // Count unique characters in t that must match their required count
        int required = 0;
        for (int count : target_counts) {
            if (count > 0) required++;
        }

        // Frequencies in the current window of s
        vector<int> window_counts(128, 0);

        int left = 0, right = 0;
        int formed = 0; // Tracks unique characters matching target frequencies

        // Track the best window found: {window_length, start_index}
        int min_len = INT_MAX;
        int start_idx = 0;

        while (right < s.length()) {
            char c = s[right];
            window_counts[c]++;

            // If the current character's frequency reaches the required frequency in t
            if (target_counts[c] > 0 && window_counts[c] == target_counts[c]) {
                formed++;
            }

            // Look for opportunities to shrink the window from the left
            while (left <= right && formed == required) {
                char left_char = s[left];

                // Save the smallest window details
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start_idx = left;
                }

                // Remove the character at the left pointer from the window counts
                window_counts[left_char]--;
                if (target_counts[left_char] > 0 && window_counts[left_char] < target_counts[left_char]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return (min_len == INT_MAX) ? "" : s.substr(start_idx, min_len);
    }
};
