class Solution {
public:
    // Time: O(mn)
    // Space: O(1)
    char *strStr(char *haystack, char *needle) {
        if (!*needle) {
            return haystack;
        }
        char *p = haystack;
        char *q = needle;
        char *pAdv = haystack;
        while (*++q) { // move pAdv m-1 forward
            pAdv++;
        }
        while (*pAdv) {
            char *pBegin = p;
            q = needle;
            while (*p && *q && *p == *q) {
                p++;
                q++;
            }
            if (!*q) {
                return pBegin;
            }
            p = pBegin + 1;
            pAdv++;
        }
        return NULL;
    }
};
