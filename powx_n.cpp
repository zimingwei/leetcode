class Solution {
private:
    double power(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double tmp = power(x, n/2);
        if (n % 2 == 0) {
            return tmp * tmp;
        } else {
            return x * tmp * tmp;
        }
    }
public:
    // Time: O(logn)
    // Space: O(logn)
    double pow(double x, int n) {
        if (n < 0) {
            return 1 / power(x, -n);
        } else {
            return power(x, n);
        }
    }
};
