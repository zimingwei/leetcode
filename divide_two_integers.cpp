class Solution {
public:
    // Time: O(logn)
    // Space: O(1)
    int divide(int dividend, int divisor) {
        int result = 0;
        bool positive = (dividend > 0 && divisor > 0) ||
                        (dividend < 0 && divisor < 0);
        long long a = (dividend >= 0) ? dividend : -(long long)dividend;
        long long b = (divisor >= 0) ? divisor : -(long long)divisor;
        while (a >= b) {
            long long c = b;
            for (int i = 0; a >= c; i++) {
                a -= c;
                result += (1 << i);
                c <<= 1;
            }
        }
        return positive ? result : -result;
    }
};
