class Solution {
public:
    // Time: O(mn)
    // Space: O(n)
    // f[i][j] = f[i-1][j] + f[i][j-1] if grid[i][j] == 0
    //           0 if grid[i][j] == 1
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        
        vector<int> f(n, 0);
        f[0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                } else if (j > 0) {
                    f[j] += f[j-1];
                }
            }
        }
        return f[n-1];
    }
};
