class Solution {
public:
    // Time: O(mn), where m is avarage string length, n is number of strings
    // Space: O(1)
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        for (int index = 0; index < strs[0].length(); index++) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[0][index] != strs[i][index]) {
                    return strs[0].substr(0, index);
                }
            }
        }
        return strs[0];
    }
};
