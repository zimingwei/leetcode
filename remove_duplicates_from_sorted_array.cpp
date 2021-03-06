class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (A[index] != A[i]) {
                index++;
                A[index] = A[i];
            }
        }
        return index + 1;
    }
};
