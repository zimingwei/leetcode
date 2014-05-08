class Solution {
public:
    // Time: O(n^2)
    // Space: O(n)
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i-1; j > 0; j--) {
                result[j] = result[j-1] + result[j];
            }
            result.push_back(1);
        }
        return result;
    }
};
