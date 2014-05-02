class Solution {
public:
    // Time: O(2^n)
    // Space: O(2^n)
    vector<int> grayCode(int n) {
        vector<int> result = {0};
        for (int i = 0; i < n; i++) {
            int prefix = 1 << i;
            for (int j = result.size()-1; j >= 0; j--) {
                result.push_back(prefix | result[j]);
            }
        }
        return result;
    }
};
