class Solution {
public:
    // Time: O(n^2), where n is the total number of rows in the triangle.
    // Space: O(n), where n is the total number of rows in the triangle.
    // Let f[i][j] be the minimum path sum from bottom to top
    // f[i][j] = min(f[i+1][j], f[i+1][j+1]) + triangle[i][j]
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> f(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                f[j] = min(f[j], f[j+1]) + triangle[i][j];
            }
        }
        return f[0];
    }
};
