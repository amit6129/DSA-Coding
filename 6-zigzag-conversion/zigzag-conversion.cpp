class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if rows = 1 or the row count is greater than or equal to string length, 
        // the string remains unchanged because no true zigzag pattern is formed.
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        // Create a bucket for each row to group elements going into the same horizontal line
        vector<string> rows(min(numRows, (int)s.length()));
        int currRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[currRow] += c;
            
            // Flip direction flag when hitting the boundaries (row 0 or row numRows - 1)
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move up or down depending on the current direction flag
            currRow += goingDown ? 1 : -1;
        }
        
        // Concatenate all row buckets together from top to bottom
        string result = "";
        for (const string& row : rows) {
            result += row;
        }
        
        return result;
    }
};
