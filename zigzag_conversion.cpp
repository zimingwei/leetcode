class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    string convert(string s, int nRows) {
        if (nRows <= 1) {
            return s;
        }
        
        string result;
        int zigzagSize = 2 * nRows - 2;
        for (int i = 0; i < nRows; i++) {
            for (int j = i; j < s.length(); j += zigzagSize) {
                result.push_back(s[j]);
                if (i > 0 && i < nRows-1) {
                    if (j + zigzagSize - 2 * i < s.length()) {
                        result.push_back(s[j+zigzagSize-2*i]);
                    }
                }
            }
        }
        return result;
    }
};
