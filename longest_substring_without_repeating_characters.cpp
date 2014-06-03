class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int lengthOfLongestSubstring(string s) {
        int last[256];
        fill(last, last+256, -1);
        int len = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (last[s[i]] >= 0) {
                maxLen = max(len, maxLen);
                len = 0;
                i = last[s[i]] + 1;
                fill(last, last+256, -1);
            }
            last[s[i]] = i;
            len++;
        }
        return max(len, maxLen);
    }
};
