class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    void reverseWords(string &s) {
        string result;
        for (int i = s.length() - 1; i >= 0; ) {
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            if (i < 0) {
                break;
            }
            int j = i;
            while (j >= 0 && s[j] != ' ') {
                j--;
            }
            if (result.length() > 0) {
                result.append(" ");
            }
            result.append(s.substr(j+1, i-j));
            i = j;
        }
        s = result;
    }
};
