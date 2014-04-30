class Solution {
public:
    // Time: O(n^2)
    // Space: O(n^2)
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        vector<int> row;
        for (int i = 0; i < numRows; i++) {
            for (int j = i-1; j > 0; j--) {
                row[j] = row[j-1] + row[j];
            }
            row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};
