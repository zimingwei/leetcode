class Solution {
private:
    string generateNext(string &s) {
        string next;
        int count = 0;
        char c = s[0];
        for (int i = 0; i <= s.length(); i++) {
            if (s[i] == c) {
                count++;
            } else {
                next += to_string(count) + c;
                count = 1;
                c = s[i];
            }
        }
        return next;
    }
public:
    // Time: O(?)
    // Space: O(n)
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            s = generateNext(s);
        }
        return s;
    }
};
