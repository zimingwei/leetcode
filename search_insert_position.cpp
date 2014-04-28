class Solution {
public:
    // Time: O(logn)
    // Space: O(1)
    int searchInsert(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;
        int result = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] > target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
