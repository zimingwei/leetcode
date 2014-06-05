class Solution {
private:
    string expand(string &s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }

public:
    // Time: O(n^2)
    // Space: O(1)
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return s;
        }
        string longest = s.substr(0, 1);
        for (int i = 0; i < s.length()-1; i++) {
            string ss = expand(s, i, i);
            if (ss.length() > longest.length()) {
                longest = ss;
            }
            ss = expand(s, i, i+1);
            if (ss.length() > longest.length()) {
                longest = ss;
            }
        }
        return longest;
    }
};
