class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int jump(int A[], int n) {
        int reach = 0;
        int step = 0;
        int maxReach = 0;
        
        for (int i = 0; i < n; ) {
            if (reach >= n - 1) {
                break;
            }
            while (i <= reach) {
                maxReach = max(maxReach, i+A[i]);
                i++;
            }
            reach = maxReach;
            step++;
        }
        return step;
    }
};
