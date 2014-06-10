class Solution {
public:
    // Time: O(n^2)
    // Space: O(n)
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
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
};
