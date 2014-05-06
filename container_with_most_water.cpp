class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int maxArea(vector<int> &height) {
        int max = INT_MIN;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int area = (j - i) * min(height[i], height[j]);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
            if (max < area) {
                max = area;
            }
        }
        return max;
    }
};
