class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    // Greedy. 
    bool canJump(int A[], int n) {
        int reach = 0;
        for (int i = 0; i <= reach && reach < n-1; i++) {
            reach = max(reach, A[i]+i);
        }
        return reach >= n-1;
    }
};
