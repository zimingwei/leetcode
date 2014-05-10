class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int trap(int A[], int n) {
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        int sum = 0;
        
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i-1], A[i-1]);
        }
        for (int i = n-2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i+1], A[i+1]);
        }
        for (int i = 0; i < n; i++) {
            int height = min(maxLeft[i], maxRight[i]);
            if (height > A[i]) {
                sum += height - A[i];
            }
        }
        return sum;
    }
};
