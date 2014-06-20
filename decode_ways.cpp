class Solution {
public:
    // Let f[i+1] be the number of ways decoding s[0...i]
    // f[i] = f[i-1] if s[i-1] is valid
    // f[i] = f[i-1] + f[i-2] if (s[i-2], s[i-1]) is valid.
    // Time: O(n)
    // Space: O(n)
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        vector<int> f(n+1, 0);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i-1] > '0' && s[i-1] <= '9') {
                f[i] += f[i-1];
            }
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7')) {
                f[i] += f[i-2];
            } 
            if (s[i-1] == '0' && !(s[i-2] == '1' || s[i-2] == '2')) {
                return 0;
            }
        }
        return f[n];
    }
};
