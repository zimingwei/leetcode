class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int singleNumber(int A[], int n) {
        int nBits = sizeof(int) * 8; // Number of bits
        vector<int> count(nBits, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nBits; j++) {
                count[j] += (A[i] >> j) & 1;
                count[j] %= 3;
            }
        }
        int result = 0;
        for (int i = 0; i < nBits; i++) {
            result += (count[i] << i);
        }
        return result;
    }
};
