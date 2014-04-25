class Solution {
public:
    // Time: O(n)
    // Space: O(1) 
    int singleNumber(int A[], int n) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result ^= A[i]; // exclusive or
        }
        return result;
    }
};
