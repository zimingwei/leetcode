class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int maxSubArray(int A[], int n) {
        int max = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum < 0) {
                sum = 0;
            }
            sum += A[i];
            if (max < sum) {
                max = sum;
            }
        }
        return max;
    }
};
