class Solution {
public:
    // Time: O(mn)
    // Space: O(1)
    bool isMatch(const char *s, const char *p) {
        bool star = false;
        const char *prevS = s;
        const char *prevP = p;
        while (*s != '\0') {
            if (*s == *p || *p == '?') {
                s++;
                p++;
                continue;
            }
            if (*p == '*') {
                star = true;
                while (*p == '*') {
                    p++;
                }
                if (*p == '\0') {
                    return true;
                }
                prevS = s;
                prevP = p;
            } else if (star) {
                prevS++;
                s = prevS;
                p = prevP;
            } else {
                return false;
            }
        }
        while (*p == '*') {
            p++;
        }
        return *p == '\0';
    }
};
