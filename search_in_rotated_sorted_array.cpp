class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) {
                return mid;
            } 
            if (A[mid] >= A[left]) { // A[mid] is always greater than or equal to A[left]
                if (target >= A[left] && target < A[mid]) { // target is less than A[mid]
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > A[mid] && target <= A[right]) { // target is greater than A[mid]
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
