class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    void sortColors(int A[], int n) {
        int red = 0;
        int blue = n - 1;
        int i = 0;
        while (i <= blue) {
            if (A[i] == 0) {
                swap(A[i], A[red]);
                i++;
                red++;
            } else if (A[i] == 2) {
                swap(A[i], A[blue]);
                blue--;
            } else {
                i++;
            }
        }
    }
};
