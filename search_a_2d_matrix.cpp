class Solution {
public:
    // Time: O(log(mn))
    // Space: O(1)
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int first = 0;
        int last = m * n - 1;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            int val = matrix[mid/n][mid%n];
            if (val == target) {
                return true;
            } else if (val < target) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
        return false;
    }
};
