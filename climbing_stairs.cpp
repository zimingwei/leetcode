class Solution {
public:
    // To reach nth level, either from (n-1)th level or (n-2)th level
    // f[n] = f[n-1] + f[n-2]
    // Time: O(n)
    // Space: O(n)
    int climbStairs(int n) {
        vector<int> f(n+1);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};
