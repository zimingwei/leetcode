class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int lengthOfLastWord(const char *s) {
        int len = 0;
        int result = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ') {
                len = 0;
            } else {
                len++;
                result = len;
            }
        }
        return result;
    }
};
