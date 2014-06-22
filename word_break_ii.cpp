class Solution {
private:
    void DFS(string &s, unordered_set<string> &dict, int start, 
             string sentence, vector<string> &result) {
        for (int i = start+1; i <= s.length(); i++) {
            if (dict.count(s.substr(start, i-start))) {
                if (i == s.length()) {
                    result.push_back(sentence + s.substr(start, i-start));
                } else {
                    DFS(s, dict, i, sentence+s.substr(start, i-start)+" ", result);
                }
            }
        }
    }
    
    bool wordBreakHelper(string &s, unordered_set<string> &dict) {
        int n = s.length();
        vector<bool> f(n+1, false);
        f[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (f[j] && dict.count(s.substr(j, i-j))) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
    
public:
    // Time: O(2^n)
    // Space: O(n)
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;
        if (wordBreakHelper(s, dict)) {
            DFS(s, dict, 0, "", result);
        }
        return result;
    }
};
