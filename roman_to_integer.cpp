class Solution {
private:
    int value(char c) {
        switch (c) {
            case 'I': 
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
public:
    // Time: O(n)
    // Space: O(1)
    int romanToInt(string s) {
        int result = 0;
        int prev = 0; // value of previous symbol
        for (int i = 0; i < s.size(); i++) {
            int curr = value(s[i]);
            if (curr > prev) {
                result += curr - 2 * prev;
            } else {
                result += curr;
            }
            prev = curr;
        }
        return result;
    }
};
