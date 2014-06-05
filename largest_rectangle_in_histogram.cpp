class Solution {
public:
    // Time: O(n)
    // Space: O(n)
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
};
