class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int removeElement(int A[], int n, int elem) {
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != elem) {
                A[index] = A[i];
                index++;
            }
        }
        return index;
    }
};
