class Solution {
private:
    // C(n, r) = n*(n-1)*...*(n-r+1) / r*(r-1)*...*1
    long long combination(int n, int r) {
        long long result = 1;
        for (int i = 1; i <= r; i++) {
            result *= n - i + 1;
            result /= i;
        }
        return result;
    }
public:
    // Time: O(min(m, n))
    // Space: O(1)
    int uniquePaths(int m, int n) {
        return combination(m+n-2, min(m-1, n-1));
    }
};
