class Solution {
private:
    void DFS(int n, int l, int r, string s, vector<string> &result) {
        if (r == n) {
            result.push_back(s);
            return;
        }
        if (l < n) {
            DFS(n, l+1, r, s+"(", result);
        }
        if (r < l) {
            DFS(n, l, r+1, s+")", result);
        }
    }
public:
    // Time: O(2^(2n))
    // Space: O(2n)
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        DFS(n, 0, 0, "", result);
        return result;
    }
};
