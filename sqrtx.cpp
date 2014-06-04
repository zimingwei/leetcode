class Solution {
public:
    // Time: O(logn)
    // Space: O(1)
    int sqrt(int x) {
        if (x < 2) {
            return x;
        }
        
        int low = 1;
        int high = x / 2;
        int last_mid = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int v = x / mid;
            if (v > mid) {
                low = mid + 1;
                last_mid = mid;
            } else if (v < mid) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return last_mid;
    }
};
