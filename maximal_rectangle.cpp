class Solution {
private:
    int largestRectangleArea(vector<int> &height) {
        stack<int> S;
        height.push_back(0);
        int result = 0;
        for (int i = 0; i < height.size(); ) {
            if (S.empty() || height[i] > height[S.top()]) {
                S.push(i);
                i++;
            } else {
                int tmp = S.top();
                S.pop();
                int width = S.empty() ? i : i - S.top() - 1;
                int area = height[tmp] * width;
                result = max(result, area);
            }
        }
        return result;
    }

public:
    // Time: O(n^2)
    // Space: O(n)
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<int> height(n, 0);
        int maxRect = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    height[j]++;
                }
            }
            maxRect = max(maxRect, largestRectangleArea(height));
        }
        return maxRect;
    }
};
