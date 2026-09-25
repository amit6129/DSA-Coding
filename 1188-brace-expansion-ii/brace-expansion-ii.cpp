class Solution {
public:
    set<string> make(string s) {
        int level = 0, i = 0;
        set<string> res;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '{') ++level;
            else if (s[j] == '}') --level;
            else if (s[j] == ',' && level == 0) {
                set<string> left = make(s.substr(0, j));
                set<string> right = make(s.substr(j + 1));
                res.insert(left.begin(), left.end());
                res.insert(right.begin(), right.end());
                return res;
            }
        }
        
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '{') {
                int level = 1, k = j + 1;
                while (k < s.size() && level > 0) {
                    if (s[k] == '{') ++level;
                    else if (s[k] == '}') --level;
                    ++k;
                }
                set<string> left = make(s.substr(0, j));
                set<string> middle = make(s.substr(j + 1, k - j - 2));
                set<string> right = make(s.substr(k));
                
                set<string> prod1;
                if (left.empty()) prod1 = middle;
                else {
                    for (const string& a : left) {
                        for (const string& b : middle) {
                            prod1.insert(a + b);
                        }
                    }
                }
                
                if (right.empty()) return prod1;
                set<string> final_res;
                for (const string& a : prod1) {
                    for (const string& b : right) {
                        final_res.insert(a + b);
                    }
                }
                return final_res;
            }
        }
        
        res.insert(s);
        return res;
    }

    vector<string> braceExpansionII(string expression) {
        set<string> s = make(expression);
        return vector<string>(s.begin(), s.end());
    }
};
